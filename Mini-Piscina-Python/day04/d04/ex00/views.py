from django.shortcuts import render
from django.http import HttpResponse

# def bar(requests):
    # return HttpResponse("<h1>bar.</h1>")

def withtemplates(request):
    return render(request, "./ex00/index.html")
# Create your views here.
