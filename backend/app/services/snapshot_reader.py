import json
import time
from pathlib import Path

SNAPSHOT_PATH = Path(__file__).resolve().parents[3] / "data" / "live_aircraft.json"

class SnapshotReader:
    def __init__(self, path: Path = SNAPSHOT_PATH):
        self.path = path

    def _read_payload(self) -> dict:
        if not self.path.exists():
            return {"generated_at": None, "count": 0, "aircraft": []}

        with self.path.open("r", encoding="utf-8") as f:
            return json.load(f)

    def get_all(self) -> list[dict]:
        return self._read_payload().get("aircraft", [])

    def get_one(self, icao24: str) -> dict | None:
        key = icao24.lower()
        for item in self.get_all():
            if str(item.get("icao24", "")).lower() == key:
                return item
        return None

    def get_health(self, stale_after_seconds: int = 15) -> dict:
        payload = self._read_payload()
        generated_at = payload.get("generated_at")
        count = payload.get("count", 0)

        if generated_at is None:
            return {
                "status": "no_snapshot",
                "snapshot_age_seconds": None,
                "aircraft_count": count,
            }

        age = max(0, int(time.time() - int(generated_at)))
        return {
            "status": "ok" if age <= stale_after_seconds else "stale",
            "snapshot_age_seconds": age,
            "aircraft_count": count,
        }