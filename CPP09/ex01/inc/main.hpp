/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 07:30:45 by marvin            #+#    #+#             */
/*   Updated: 2024/03/14 11:14:20 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP
#include <stack>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <bits/stdc++.h>

int convert (std::string str);
int operate (int val, int str, char op);
void check_operator(std::string str, std::stack<int> my_oper);

#endif
