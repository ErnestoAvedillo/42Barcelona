from django.urls import path
from django.conf.urls.static import static
from .views import *
handler404 = custom_404_view

urlpatterns = [
    path('login_user/', login_user, name='login_user'),
    path('create_user/', create_user, name='create_user'),
    path('is_logged_in/', is_logged_in, name='is_logged_in'),
    path('logout_user/', logout_user, name='logout_user'),
    path('list_users/', list_users, name='list_users'),
    path('user_status/', user_status, name='user_status'),
    path('send_friend_request/', send_friend_request, name='send_friend_request'),
    path('change_friendship_status/', change_friendship_status, name='change_friendship_status'),
    path('get_friends/', get_friends, name='get_friends'),
    path('get_pending_friendships/', get_pending_friendships, name='get_pending_friendships'),
    path('update_user/', update_user, name='update_user'),
    path('get_profile_picture_url/<str:username>/', get_profile_picture_url, name='get_profile_picture'),
    path('upload_picture/', upload_picture, name='upload_picture'),
    path('get_profile/<str:username>/', get_profile, name='get_profile'),
    path('check_user/', check_user, name='check_user'),

]

