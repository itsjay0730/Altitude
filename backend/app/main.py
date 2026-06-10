from fastapi import FastAPI
from app.routes.enrichment import router as enrichmentRouter
from app.routes.aircraft import router as aircraftRouter
from app.routes.health import router as healthRouter

app = FastAPI()

app.include_router(enrichmentRouter)
app.include_router(aircraftRouter)
app.include_router(healthRouter)