from fastapi import APIRouter
from app.services.snapshot_reader import SnapshotReader

router = APIRouter(tags=["health"])
reader = SnapshotReader()

@router.get("/health")
def health():
    return reader.get_health(stale_after_seconds=15)