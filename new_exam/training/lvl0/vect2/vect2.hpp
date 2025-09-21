/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:14:17 by mbany             #+#    #+#             */
/*   Updated: 2025/09/21 14:55:44 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class vect2 {
	public:
		int x;
		int y;
	private:
	vect2();
	vect2(int num1, int num2);
	vect2(const vect2& source);
	~vect2();

	vect2& operator=(const vect2& source);
	
	vect2& operator+=(const vect2& obj);
	vect2& operator-=(const vect2& obj);
	vect2& operator*=(const vect2& obj);
	
	vect2 operator+(const vect2& obj) const;
	vect2 operator-(const vect2& obj) const;
	vect2 operator*(const vect2& obj) const;
	

};
vect2 operator*(int num, const vect2& obj);

std::ostream operator<<(std::ostream os, const vect2& obj);