import os
import requests
from dotenv import load_dotenv
from fastapi import FastAPI

load_dotenv()
AIRLABS_API_KEY = os.getenv("AIRLABS_API_KEY")


