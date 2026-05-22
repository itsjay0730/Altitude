import os
import requests
from dotenv import load_dotenv
from fastapi import FastAPI

load_dotenv()
AIRLABS_API_KEY = os.getenv("AIRLABS_API_KEY")

router = APIRouter()

@router.get("/enrichment/{icao24}")
def enrichment(icao24: str):
    url = f"https://airlabs.co/api/v9/flights?api_key={AIRLABS_API_KEY}&hex={icao24}"

    response = requests.get(url)
    return response.json()

