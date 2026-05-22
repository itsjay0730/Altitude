from fastapi import FastAPI
from app.routes.enrichment import router as enrichmentRouter

app = FastAPI()

app.include_router(enrichmentRouter)