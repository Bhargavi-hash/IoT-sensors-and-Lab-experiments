from datetime import datetime

import requests
import json
import matplotlib.pyplot as plt

ae = "pir_sensor"
cnt = "node1"

uri_cse = "http://127.0.0.1:8080/~/in-cse/in-name"
uri_ae = uri_cse + "/" + ae
uri_cnt = uri_ae + "/" + cnt

uri_req = uri_cnt + "/?rcn=4"

headers = {
    'X-M2M-Origin': 'admin:admin',
    'Content-type': 'application/json'
}

response = requests.get(uri_req, headers=headers)
res = json.loads(response.text)
print(res)

cins = res["m2m:cnt"]["m2m:cin"]

x = []
y = []

for cin in cins:
    dt = datetime.strptime(cin["ct"], '%Y%m%dT%H%M%S')
    x.append(dt)
    y.append(float(cin["con"]))



plt.plot(x, y)
plt.xlabel("time")
plt.ylabel("pir Sensor")

plt.gcf().autofmt_xdate()
plt.show()
plt.savefig('part3.jpg')