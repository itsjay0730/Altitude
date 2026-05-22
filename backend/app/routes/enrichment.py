import os
import requests
from dotenv import load_dotenv
from fastapi import APIRouter

load_dotenv()
AIRLABS_API_KEY = os.getenv("AIRLABS_API_KEY")

router = APIRouter()

@router.get("/enrichment/{icao}")
def enrichment(icao: str):
    url = f"https://airlabs.co/api/v9/flights?api_key={AIRLABS_API_KEY}&hex={icao}"

    response = requests.get(url)
    return response.json()

