#!/usr/bin/env bash
# Script auxiliar para compilar e rodar uma das fases (survival1/2/3)
set -euo pipefail

PHASE=${1:-1}

case "$PHASE" in
  1|2|3) ;;
  *)
    echo "Uso: $0 [1|2|3] [args...]"
    exit 1
    ;;
esac

echo "Compilando (make)..."
make

EXEC=./build/survival${PHASE}

if [ ! -x "$EXEC" ]; then
  echo "Executável \"$EXEC\" não encontrado ou não executável." >&2
  exit 2
fi

echo "Executando $EXEC ${@:2}..."
exec "$EXEC" "${@:2}"
