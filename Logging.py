import time
import traceback
import sys

LOGGING_START_TIME = 0

def info(msg):
    print("\033[38;5;075m"+str(round(time.time()-LOGGING_START_TIME, 3))+"\tINFO:     ", msg, "\033[0m")

def warning(msg):
    print("\033[38;5;202m\033[1m"+str(round(time.time()-LOGGING_START_TIME, 3))+"\tWARNING:  ", msg, "\033[0m\033[0m")

def error(msg):
    print("\033[38;5;196m\033[1m"+str(round(time.time()-LOGGING_START_TIME, 3))+"\tCRITICAL: ", msg, "\033[0m\033[0m")

def trace():
    print("\033[38;5;196m\033[1mBEGIN STACK TRACE\033[0m\033[0m")
    print("\033[38;5;196m")
    traceback.print_exception(*sys.exc_info())
    print("\033[0m")
    print("\033[38;5;196m\033[1mEND STACK TRACE\033[0m\033[0m")

def set_start_time(t):
    global LOGGING_START_TIME
    LOGGING_START_TIME = t
