#!/bin/bash

echo "Setting kibana_system password"
until curl -s -X POST --cacert config/certs/ca/ca.crt -u "elastic:${ELASTIC_PASSWORD}" -H "Content-Type: application/json" https://es01:9200/_security/user/kibana_system/_password -d "{\"password\":\"${KIBANA_PASSWORD}\"}" | grep -q "^{}"; do sleep 1; done;
echo "Waiting for Kibana to start..."
until curl -s -u "elastic:${ELASTIC_PASSWORD}" -s -XGET "http://kibana:5601/api/status" | grep -q "\"level\":\"available\""; do sleep 1; done
echo "Exporting dashboards to Kibana"

until curl -s -u "elastic:${ELASTIC_PASSWORD}" --cacert config/certs/ca/ca.crt "https://es01:9200/_cluster/health?pretty" | grep -q "yellow"; do sleep 1; done

until curl --max-time 600 -s -u "elastic:${ELASTIC_PASSWORD}" --cacert config/certs/ca/ca.crt -X PUT "https://es01:9200/_ilm/policy/7days_policy" -H "Content-Type: application/json" -d '{
    "policy": {
        "phases": {
        "hot": {
            "min_age": "0ms",
            "actions": {
            "rollover": {
                "max_age": "7d"
            }
            }
        },
        "delete": {
            "min_age": "7d",
            "actions": {
            "delete": {}
            }
        }
        }
    }
    }' | grep -q '"acknowledged":true'; do
    echo "Waiting for acknowledged:true..."
    sleep 1
done

until curl --max-time 600 -s -u "elastic:${ELASTIC_PASSWORD}" --cacert config/certs/ca/ca.crt -X PUT "https://es01:9200/_index_template/gateway_template" \
    -H "Content-Type: application/json" \
    -d '{
    "index_patterns": ["gate*"],
    "template": {
        "settings": {
        "index.lifecycle.name": "7days_policy",
        "index.lifecycle.rollover_alias": "gateway"
        }
    }
    }' | grep -q '"acknowledged":true'; do
    echo "Waiting for acknowledged:true..."
    sleep 1
done

until curl --max-time 600 -s -u "elastic:${ELASTIC_PASSWORD}" --cacert config/certs/ca/ca.crt -X PUT "https://es01:9200/_index_template/usermanagement_template" \
    -H "Content-Type: application/json" \
    -d '{
    "index_patterns": ["user*"],
    "template": {
        "settings": {
        "index.lifecycle.name": "7days_policy",
        "index.lifecycle.rollover_alias": "usermanagement"
        }
    }
    }' | grep -q '"acknowledged":true'; do
    echo "Waiting for acknowledged:true..."
    sleep 1
done

until curl --max-time 600 -s -u "elastic:${ELASTIC_PASSWORD}" --cacert config/certs/ca/ca.crt -X PUT "https://es01:9200/_index_template/tournaments_template" \
    -H "Content-Type: application/json" \
    -d '{
    "index_patterns": ["tour*"],
    "template": {
        "settings": {
        "index.lifecycle.name": "7days_policy",
        "index.lifecycle.rollover_alias": "tournaments"
        }
    }
    }' | grep -q '"acknowledged":true'; do
    echo "Waiting for acknowledged:true..."
    sleep 1
done

until curl --max-time 600 -s -u "elastic:${ELASTIC_PASSWORD}" --cacert config/certs/ca/ca.crt -X POST "https://es01:9200/_aliases" \
    -H "Content-Type: application/json" \
    -d '{
          "actions": [
            {
              "add": {
                "index": "gate*",
                "alias": "gateway"
              }
            }
          ]
        }'| grep -q '"acknowledged":true'; do
    echo "Waiting for acknowledged:true..."
    sleep 1
done

until curl --max-time 600 -s -u "elastic:${ELASTIC_PASSWORD}" --cacert config/certs/ca/ca.crt -X POST "https://es01:9200/_aliases" \
    -H "Content-Type: application/json" \
    -d '{
          "actions": [
            {
              "add": {
                "index": "tour*",
                "alias": "tournaments"
              }
            }
          ]
        }'| grep -q '"acknowledged":true'; do
    echo "Waiting for acknowledged:true..."
    sleep 1
done

until curl --max-time 600 -s -u "elastic:${ELASTIC_PASSWORD}" --cacert config/certs/ca/ca.crt -X POST "https://es01:9200/_aliases" \
    -H "Content-Type: application/json" \
    -d '{
          "actions": [
            {
              "add": {
                "index": "user*",
                "alias": "usermanagement"
              }
            }
          ]
        }'| grep -q '"acknowledged":true'; do
    echo "Waiting for acknowledged:true..."
    sleep 1
done

curl  --max-time 600  -u "elastic:${ELASTIC_PASSWORD}" -X POST "http://kibana:5601/api/saved_objects/_import" -H "kbn-xsrf: true" --form file=@/ELK/data_views.ndjson


echo "DONE WITH policy"




DASHBOARD_ID=$(curl  -u "elastic:${ELASTIC_PASSWORD}" -X POST "http://kibana:5601/api/saved_objects/_import" -H "kbn-xsrf: true" --form file=@/ELK/gateway_dashboard.ndjson | jq -r '.successResults[0].id')

echo  dahboard ${DASHBOARD_ID}


if [ -n "$DASHBOARD_ID" ]; then
    echo exporting settings
    until curl --user elastic:${ELASTIC_PASSWORD} -X GET "http://kibana:5601/api/saved_objects/_find?type=config" -H "kbn-xsrf: true" | grep \"id\":\"8.7.1\"; do sleep 1; done;
    curl \
    --user elastic:${ELASTIC_PASSWORD} \
    -X PUT http://kibana:5601/api/saved_objects/config/8.7.1 \
    -H "Content-Type: application/json; Elastic-Api-Version=2023-10-31" \
    -H "kbn-xsrf: true"\
    -d "{\"attributes\": {\"defaultRoute\": \"/app/dashboards#/view/${DASHBOARD_ID}\"}}"
else
    echo Not exporting
fi

echo "All done!"