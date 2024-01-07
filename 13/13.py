import random
icerde = 0
for atis_sayisi in range(0, 1000000):
    a = random.random()
    b = random.random()
    z= (a*a+b*b)**0.5
    if z < 1:
    	icerde+= 1
atis_sayisi+= 1
print("Pi sayisinin yaklasik degeri:",4.0 * icerde / atis_sayisi)