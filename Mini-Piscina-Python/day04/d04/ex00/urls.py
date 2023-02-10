from django.contrib import admin
from django.urls import path, include
from . import views

urlpatterns = [
    path('ex00', views.withtemplates )
]