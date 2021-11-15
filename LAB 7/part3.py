from onem2m import *

uri_cse = "http://127.0.0.1:8080/~/in-cse/in-name"
ae = "pir_sensor"
cnt = "node1"

create_ae(uri_cse, ae)

uri_ae = uri_cse + "/" + ae
create_cnt(uri_ae, cnt)

uri_cnt = uri_ae + "/" + cnt
create_data_cin(uri_cnt, "random_value")

# https://f1b4-223-230-125-145.ngrok.io -- Part1
# https://66dd-223-230-125-145.ngrok.io -- Part2

