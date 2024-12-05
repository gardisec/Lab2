#include "task4.h"

void sortBlocks(arr<Block>& blocks) {
    for (size_t i = 0; i < blocks.size; ++i) {
        for (size_t j = i + 1; j < blocks.size; ++j) {
            if (blocks[i].width > blocks[j].width ||
            (blocks[i].width == blocks[j].width && blocks[i].height < blocks[j].height)) {
                Block temp = blocks[i];
                blocks[i] = blocks[j];
                blocks[j] = temp;
            }
        }
    }
}

void task4() {
    size_t N;
    cin >> N;
    int w, h;
    arr<Block> blocks(N);
    for (size_t i = 0; i < N; ++i) {
        cin >> w >> h;
        blocks[i] = Block(w, h);
    }
    sortBlocks(blocks);//сортируем блоки

    int maxHeight = 0;
    int currentWidth = -1;
    for (size_t i = 0; i < blocks.size; ++i) {//построение пирамиды
        if (blocks[i].width > currentWidth) {
            maxHeight += blocks[i].height;
            currentWidth = blocks[i].width;
        }
    }

    cout << maxHeight << endl;
}