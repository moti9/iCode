import phonenumbers
import opencage
import folium
from myphone import number

from phonenumbers import geocoder

pepnumber = phonenumbers.parse(number)

location = geocoder.description_for_number(pepnumber, "en")

print(location)

from phonenumbers import carrier

service_pro = phonenumbers.parse(number)
print(carrier.name_for_number(service_pro, "en"))

from opencage.geocoder import OpenCageGeocode


key = "f8d6df9e42554d51bdb1b34a11c79f3a"

geocoder = OpenCageGeocode(key)
query = str(location)
results = geocoder.geocode(query)
print(results)

lat = results[0]["geometry"]["lat"]
lng = results[0]["geometry"]["lng"]
# import json
# rst=json.dumps(results)
# print(rst)
print(lat, lng)

mymap = folium.Map(location=[lat, lng], zoom_start=9)
folium.Marker([lat,lng],popup=location).add_to(mymap)

mymap.save('mylocation.html')
