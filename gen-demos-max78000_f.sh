#!/bin/sh
DEVICE="MAX78000"
COMMON_ARGS="--device $DEVICE --energy --display-checkpoint --verbose"

python ai8xize.py --test-dir "/home/merveeyuboglu/Github/ai8x-synthesis/boardtest/BOARDTEST_EV" --prefix kws20_v2 --checkpoint-file trained/ai85-kws20_v2-qat8-q.pth.tar --config-file networks/kws20-v2-hwc.yaml --board-name EvKit_V1 --softmax $COMMON_ARGS "$@"
python ai8xize.py --test-dir "/home/merveeyuboglu/Github/ai8x-synthesis/boardtest/BOARDTEST_EV" --prefix kws20_v3 --checkpoint-file trained/ai85-kws20_v3-qat8-q.pth.tar --config-file networks/kws20-v3-hwc.yaml --board-name EvKit_V1 --softmax $COMMON_ARGS "$@"
python ai8xize.py --test-dir "/home/merveeyuboglu/Github/ai8x-synthesis/boardtest/BOARDTEST_EV" --prefix kws20_nas --checkpoint-file trained/ai85-kws20_nas-qat8-q.pth.tar --config-file networks/kws20-nas-hwc.yaml --board-name EvKit_V1 --softmax $COMMON_ARGS "$@"

