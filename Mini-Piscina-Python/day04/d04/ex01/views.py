from django.shortcuts import render

def display(request):
    return render(request, "./ex01/display.html")

def django_page(request):
    return render(request, "./ex01/django.html")

def template_page(request):
    return render(request, "./ex01/template.html")
