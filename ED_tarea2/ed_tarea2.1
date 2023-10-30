#include "DeBlock.hpp"
#include "Lista.hpp"
#include "ListaDeListas.hpp"

DeBlock::DeBlock(int* elems, int n, int b) {
    cant_elems = n;
    blockSize = b;
    int num_blocks = (n + b - 1) / b;
    listArray = new tListaDeListas(num_blocks);

    for (int i = 0; i < num_blocks; i++) {
        tLista sub_list;
        for (int j = 0; j < b && (i * b + j < n); j++) {
            sub_list.insert(sub_list.length(), elems[i * b + j]);
        }
        listArray->append(sub_list);
    }
}

DeBlock::~DeBlock() {
    delete listArray;
}

int DeBlock::insert(int pos, int elem) {
    if (pos < 0 || pos > cant_elems) {
        return 0;
    }

    int block_index = pos / blockSize;
    int pos_in_block = pos % blockSize;

    if (listArray->get_value(block_index).length() >= blockSize) {
        return 0;
    }

    listArray->get_value(block_index).insert(pos_in_block, elem);
    cant_elems++;
    return 1;
}


int DeBlock::get_value(int pos) {
    if (pos < 0 || pos >= cant_elems) {
        return -1;
    }

    int block_index = pos / blockSize;
    int pos_in_block = pos % blockSize;

    if (block_index < length()) {
        tLista block = listArray[block_index];
        return block.get_value(pos_in_block);
    } else {
        return -1;
    }
}




int DeBlock::getBlockSize() const {
    return blockSize;
}

int DeBlock::getCantElems() const {
    return cant_elems;
}



int DeBlock::length() {
    return cant_elems;
}

int DeBlock::erase(int pos) {
    if (pos < 0 || pos >= cant_elems) {
        return -1;
    }

    int block_index = pos / blockSize;
    int pos_in_block = pos % blockSize;

    int erased_value = listArray->get_value(block_index).erase(pos_in_block);
    cant_elems--;
    return erased_value;
}

void DeBlock::clear() {
    listArray->clear();
    cant_elems = 0;
}
