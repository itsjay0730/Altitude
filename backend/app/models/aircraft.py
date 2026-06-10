from pydantic import BaseModel

class Aircraft(BaseModel):
    icao24: str
    callsign: str | None = None
    originCountry: str | None = None
    time: int | None = None
    lastContact: int | None = None
    longitude: float | None = None
    latitude: float | None = None
    altitude: float | None = None
    velocity: float | None = None
    direction: float | None = None
    altitudeRate: float | None = None
    inAir: bool | None = None
    squawk: str | None = None
    spi: bool | None = None
    source: int | None = None