#!/usr/bin/bash
docker run -i -t --name bfs -w /app -v $(pwd):/app -d ubuntu:19.04
