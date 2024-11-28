FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    libomp-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /codes

COPY vulnerable.c /codes/vulnerable.c
COPY corregidoOMP.c /codes/corregidoOMP.c
COPY corregidoSEICERT.c /codes/corregidoSEICERT.c

CMD ["/bin/bash"]