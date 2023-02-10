from django.contrib import admin
from django.urls import path, include
from . import views

urlpatterns = [
    path('ex01/display/', views.display ),
    path('ex01/django/', views.django_page),
    path('ex01/template/', views.template_page)
]