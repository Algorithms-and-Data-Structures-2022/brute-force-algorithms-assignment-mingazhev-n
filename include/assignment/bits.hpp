#pragma once

#include <vector>

namespace assignment {

  /**
   * Проверка разряда на указанной позиции битовой маски.
   *
   * Например:                     3 2 1 0  <- разряды (pos)
   * 9 (10ая СС) = 1001 (2ая СС) = 1 0 0 1  <- mask
   * бит установлен на позициях pos = 3 и pos = 0
   *
   * проверка разряда на позиции 3:   1 0 0 1
   *                                & 1 0 0 0  <- проверочная маска
   *                                ---------
   *                                  1 0 0 0 = 8 (10ая СС)
   *
   * проверка разряда на позиции 2:   1 0 0 1
   *                                & 0 1 0 0  <- проверочная маска
   *                                ---------
   *                                  0 0 0 0 = 0 (10ая СС)
   *
   * @param mask - неотрицательная целочисленная битовая маска
   * @param pos - разряд/позиция проверки бита в битовой маске
   * @return true - бит установлен, false - бит не установлен
   */
  bool is_bit_set(int mask, int pos);

  /**
   * Установка разряда на указанной позиции битовой маски.
   *
   * Например:                     3 2 1 0  <- разряды (pos)
   * 8 (10ая СС) = 1000 (2ая СС) = 1 0 0 0  <- mask
   * бит не установлен на позиции pos = 1 и установлен на позиции pos = 3
   *
   * установка разряда на позиции 1:  1 0 0 0
   *                                | 0 0 1 0  <- маска, устанавливающая бит
   *                                ---------
   *                                  1 0 1 0 = 10 (ая СС)
   *
   * установка разряда на позиции 3:  1 0 0 0
   *                                | 1 0 0 0  <- маска, устанавливающая бит
   *                                ---------
   *                                  1 0 0 0 = 8 (10ая СС)
   *
   * @param mask - неотрицательное целочисленная битовая маска
   * @param pos - разряд/позиция установки разряда в битовой маске
   * @return битовая маска с установленным разрядом
   */
  int set_bit(int mask, int pos);

  /**
   * Генерация массива из индексов по установленным разрядам в битовой маске.
   *
   * @param elems - массив элементов
   * @param mask - битовая маска
   * @return массив индексов (не элементов)
   */
  std::vector<int> mask2indices(const std::vector<int>& elems, int mask);

  /**
   * Генерация массива из элементов по установленным разрядам в битовой маске.
   *
   * @param elems  - массив элементов
   * @param mask - битовая маска
   * @return массив элементов
   */
  std::vector<int> mask2elems(const std::vector<int>& elems, int mask);

}  // namespace assignment