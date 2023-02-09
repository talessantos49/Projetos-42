#!/usr/bin/env python3

import antigravity, sys

def check_arguments(arguments):
    if len (arguments) == 4:
        try:
            latitu = float(arguments[1])
        except:
            print("Error: Latitudes information need to be a float value! ex: 111.1111")
            exit(1)
        try:
            longit = float(arguments[2])
        except:
            print("Error: Longitudes information need to be a float value!ex: 111.1111")
            exit(1)
        try:
            dateD = bytes(arguments[3].encode("UTF-8"))
        except:
            print("Error: Date and Down information need to be this format : year-month-day-DowOpening!")
            exit(1)

        return(latitu, longit, dateD)
    elif len (arguments) > 4:
        print("Error: Error: Too many, arguments! ")
        exit(1)
    elif len(arguments) < 4 :
        print("Error: Too few, arguments!")
        exit(1)
         

if __name__ =="__main__":

    arguments = check_arguments(sys.argv)
    latitude = arguments[0]
    longitude = arguments[1]
    dateDow = arguments[2]

    antigravity.geohash(latitude, longitude, dateDow)
