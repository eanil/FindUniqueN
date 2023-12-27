#pragma once

#include <iostream>
#include <vector>

/**
 * Find the top @c N entries with the max value.
 * Uses a priority_queue to keep a sorted list of items.
 *
 * @param stream Reads the data from this stream. 
 * Assumes a "uniqueId, value" pair per line, where the pair is delimited 
 * with a tab, space or a comma.
 * @param N The number of values to return.
 * @return A vector of unique ids.
 */
std::vector<std::string> FindUniqueMaxN(std::istream &stream, int N);

/**
 * Find the top @c N entries with the max value.
 * Uses two stacks to keep a sorted list of items.
 *
 * @param stream Reads the data from this stream. 
 * Assumes a "uniqueId, value" pair per line, where the pair is delimited 
 * with a tab, space or a comma.
 * @param N The number of values to return.
 * @return A vector of unique ids.
 */
std::vector<std::string> FindUniqueMaxN2(std::istream &stream, int N);