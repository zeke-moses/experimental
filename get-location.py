# Python script to get location from current address
# currently only works with test address, whill
# change later

# RUN AS SUDO

from geopy.geocoders import Nominatim

geolocator = Nominatim()
location = geolocator.geocode("600 Navarro St San Antonio")
#print(location.address)
print(location.latitude, location.longitude)
