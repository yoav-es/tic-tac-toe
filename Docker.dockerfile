# -------------------------------
# Base image
# -------------------------------
FROM alpine:latest

# -------------------------------
# Install dependencies
# -------------------------------
RUN apk update && apk add --no-cache \
    build-base \
    cmake \

# -------------------------------
# Copy project files
# -------------------------------
COPY . /app
WORKDIR /app

# -------------------------------
# Build steps
# -------------------------------
RUN cmake -B build -S . && cmake --build build


# -------------------------------
# Runtime command
# -------------------------------
CMD ["./build/tictactoe"]
