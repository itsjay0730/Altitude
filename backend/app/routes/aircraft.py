from fastapi import APIRouter, HTTPException
from app.models.aircraft import Aircraft
from app.services.snapshot_reader import SnapshotReader

router = APIRouter(prefix="/aircraft", tags=["aircraft"])
reader = SnapshotReader()

@router.get("/live", response_model=list[Aircraft])
def get_live_aircraft():
    return reader.get_all()

@router.get("/{icao24}", response_model=Aircraft)
def get_aircraft_by_icao24(icao24: str):
    aircraft = reader.get_one(icao24)
    if aircraft is None:
        raise HTTPException(status_code=404, detail="Aircraft not found")
    return aircraft