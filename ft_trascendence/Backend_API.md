# Table of contents
| Section | Links |
|---------|-------|
| [User](#user) | [create_user](#create_user) <br> [login_user](#login_user) <br> [logout_user](#logout_user) <br> [is_logged_in](#is_logged_in) <br> [list_users](#list_users) <br> [user_status](#user_status) <br> [send_friend_request](#send_friend_request)<br> [change_friendship_status](#change_friendship_status)<br> [get_friends](#get_friends)<br> [get_pending_friendships](#get_pending_friendships)<br> [update_user](#update_user) <br> [get_profile_picture_url](#get_profile_picture_url)<br> [upload_picture](#upload_picture) <br> [get_profile](#get_profile) <br> [check_user](#check_user)|
|[Tournaments](#tournaments)| [open_tournament](#open_tournament) <br> [accept_invitation](#accept_invitation) <br> [close_tournament](#close_tournament) <br> [start_match](#start_match) <br>[finish_match](#finish_match) <br> [list_tournaments](#list_tournaments) <br> [list_matches](#list_matches) <br> [list_invitations](#list_invitations)|

All API calls will return a json response and the corresponding code

json response format:

{
    'status' : 'error' / 'success',
    'message' : A short message,
    'data' : None / 'Data'

}

## Testing 
There is a script to create users matches and tournemants
python gateway/gateway/tests/testing_tournaments_ea.py {ip.address} {operation}[optional]

possible operations are:
[none]: will do a complete test
match: will create matches
tournament: will create tournaments without finishing
tournament_finish: will fiish tournaments
list: will test the listing calls

## User

user/[subpath]

### create_user

Set tournament name to username by default, user can later change the tournament name

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Creates User if not in the database. | POST | {username, password, first_name, last_name} | None |  201, 409 (already exists), 400, 405, 500 |

[Back to Top](#table-of-contents)



### login_user

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Logs in User| POST | None (cookies handles it) | None |200, 400, 401 (invalid credentials), 405, 500|

[Back to Top](#table-of-contents)


### logout_user

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Logs out User| POST | None (cookies handles it) | None |200, 403 ( Forbidden), 405, 500|

[Back to Top](#table-of-contents)


### is_logged_in


| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Checks if YOUR user is logged in | GET | None | {username, id} |  200 (user logged in), 401 (Unauthorized), 405, 500|

[Back to Top](#table-of-contents)


### list_users

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Returns a list of all users registered | GET | None | List of users. Each element inside the list is a dictionaty with id and username keys |  200 (user logged in), 405, 500|

[Back to Top](#table-of-contents)


### user_status

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Returns current online status of user | GET | username | is_online: True/False |  200 , 404 (user not found), 405, 500|
| Changes current user status | POST | status: online/offline | None |  200, 400(invalid json or user not auth), 404 (user not found), 405, 500|

[Back to Top](#table-of-contents)


### send_friend_request

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Sends friend request | POST | username to send request  | None |  201 ,400, 401,404 (user not found), 405, 500|

[Back to Top](#table-of-contents)

### change_friendship_status

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Updates friendship | POST | username: friend, status: [accepted / declined]  | None |  200 ,400, 401,404 (user not found or no friendship), 405, 500|


[Back to Top](#table-of-contents)
### get_friends

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| gets friends list | GET | None | lista de diccionarios (puede estar vacia): <br> {username, <br>friendship (accepted/pending/declined),<br> is_online(True,False)}  |  200,401,405,500|


[Back to Top](#table-of-contents)

### get_pending_friendships

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| gets friends list | GET | None | lista de diccionarios (puede estar vacia) de invitaciones pendientes: <br> {username, friendship_id, profile_picture_url}  |  200,401,405,500|


[Back to Top](#table-of-contents)



### update_user

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Updates user fields: first_name, last_name, tournament_name, language | POST | first_name, last_name, tournament_name, language | None |  200,400,401,405, 500|


[Back to Top](#table-of-contents)

### get_profile_picture_url

You need to call /user/get_profile_picture_url/{username}OR{user_id}/ to get the profile picture url for {username}

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Gets profile picture url for user| GET | /username | profile_picture_url |  200,401,405, 500|




[Back to Top](#table-of-contents)


### upload_picture

You need to call /user/upload_picture/ and upload a a form with a key/value pair of picture:{picture_data} to update the picture for the signed in user. Returns profile_picture_url inside data, containing the url for the uploaded file

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Updates profile picture of user| POST | form data with picture field| profile_picture_url |  200,400,401,405, 500|


[Back to Top](#table-of-contents)


### get_profile



| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|

| Gets a user profile information| GET | username OR user_id  | lang, puntos, first_name, last_name, username, tournament_name, is_online, profile_picture_url |  200,400,401,404, 405, 500|


[Back to Top](#table-of-contents)


### check_user

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Checks if the logged in user is the same as the one in data| POST | username  | is_same(true/false) |  200, 400, 401, 404, 405, 500|


[Back to Top](#table-of-contents)
## Tournaments

### open_tournament

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
| Creates a tournament and sends invitation to all players  | POST | 'name',<BR> 'winning_points', <BR> 'date_start', <BR> 'max_players', <BR> 'cost', <BR> 'price_1', <BR> 'price_2', <BR> 'price_3', <BR> 'players':[username1, username2, ...]	 | None |  200 (tournament created), 400 (incorrect data), 404 (user not in database), 500|

[Back to Top](#table-of-contents)

### accept_invitation

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
|Payer accepts the invitation to a turnaament| POST | 'tournament_id' | None |  200 (invitation accepted), 400 (incorrect data), 404 (user not in database), 500|

[Back to Top](#table-of-contents)

### close_tournament
| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
|Closes tournament open invites, starts tournament. Payer accepts the invitation to a turnaament| POST | 'tournament_id' | None |  200 (invitation accepted), 400 (incorrect data), 404 (user not in database), 500|

[Back to Top](#table-of-contents)

### start_match
| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
|When the first player access to the match| POST | 'match_id' | None |  200 (invitation accepted), 400 (incorrect data), 404 (user not in database), 500|

[Back to Top](#table-of-contents)

### finish_match
| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
|When the match finishes, informs who is the winner| POST | 'match_id' 'winner' 'points_winner' 'looser' 'points_looser' | None |  200 (Match finished successfully), 400 (he match has already been played), 404 (user not in database), 500|

[Back to Top](#table-of-contents)

### list_tournaments
| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
|Returns a list of tournaments from registered user| GET | None | None |  200 (List of tournaments cereatedy), 500 (Internal error)|

### list_matches
You need to call /tournaments/list_matches/{username}

| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
|Returns a list of matches from registered user | GET | None | None |  200 (List of matches cereated), 500 (Internal error)|


### list_matches_by_tournament_id
You need to call /tournaments/list_matches_by_tournament_id/{username}
| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
|Returns a list of invitations from registered user | GET | None | None |  200 (List of matches cereated), 500 (Internal error)|


### list_not_played_matches
You need to call /tournaments/list_not_played_matches/{username}
| Use | Methods | Request Data | Response Data | Return Values|
| --- | --- | --- | ---| ---|
|Returns a list of invitations from registered user | GET | None | None |  200 (List of matches cereated), 500 (Internal error)|