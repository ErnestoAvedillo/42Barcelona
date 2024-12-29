from tournamentsapp.wrappers import require_get, user_is_authenticated, exception_handler
from blockchainapp.views import get_results
from tournamentsapp.models import Tournaments
from datetime import datetime
from django.db import OperationalError
from django.http import JsonResponse
from tournamentsapp.status_options import StatusTournaments
import json
import logging
from django.contrib.auth import get_user_model
logger = logging.getLogger('django')


User = get_user_model()

@require_get
@exception_handler
def list_tournaments(request, username):
    #player = request.user
	try:
		player = User.objects.get(username=username)
		tournament_data = Tournaments.objects.filter(player_id=player.id, status=StatusTournaments.OPEN_TOURNAMENT.value)
		# Convert any datetime fields to string
		tournament_list = list(tournament_data.values())
		for tournament in tournament_list:
			for key, value in tournament.items():
				if isinstance(value, datetime):
					tournament[key] = value.isoformat()
		data = json.dumps(tournament_list)
		return JsonResponse({'status': 'success', 'message': 'List of tournaments cereated', 'data': data}, status=200)
	except OperationalError:
		return JsonResponse({'status': 'error', 'message': 'Internal error', 'data': data}, status=500)


@require_get
@exception_handler
def list_tournaments_status(request, username):
    # player = request.user
	try:
		player = User.objects.get(username=username)
		tournament_data = Tournaments.objects.filter(player_id=player.id)
		# Convert any datetime fields to string
		tournament_list = list(tournament_data.values())
		data_to_return = []
		for tournament in tournament_list:
			if tournament["hash"] is not None:
				results = get_results(tournament['hash'])
			logger.info('Results: %s', results)
			if len(results) > 0:
				data_to_return.append({
					"id": tournament["id"],
					"name": tournament["name"],
					"winner": results[0],
					"second": results[1],
					"third": results[2],})
		data = json.dumps(data_to_return)
		return JsonResponse({'status': 'success', 'message': 'List of tournaments cereated', 'data': data}, status=200)
	except OperationalError:
		return JsonResponse({'status': 'error', 'message': 'Internal error', 'data': data}, status=500)
