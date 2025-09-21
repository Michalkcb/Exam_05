/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:14:17 by mbany             #+#    #+#             */
/*   Updated: 2025/09/21 14:26:22 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class vect2 {
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(int num1, int num2);
		vect2(const vect2& source);
		~vect2();
		
		bool operator==(const vect2& obj) const;
		bool operator!=(const vect2& obj) const;
		
		vect2& operator=(const vect2& source);
		
		//pozostałe operatory---------
		vect2& operator+=(const vect2& obj);
		vect2& operator-=(const vect2& obj);
		vect2& operator*=(const vect2& obj);
		
		vect2 operator+(const vect2& obj) const;
		vect2 operator-(const vect2& obj) const;
		vect2 operator*(const vect2& obj) const;
		
		vect2 operator-() const;
		vect2 operator*(int num) const;
		
		vect2& operator*=(int num);
		
		vect2& operator++();
		vect2& operator--();
		vect2 operator++(int ) const;
		vect2 operator--(int ) const;

		int operator[](int index) const;
		int& operator[](int index);
		//---------
	};
	
vect2& operator*(int num, const vect2& obj);

std::ostream& operator<<(std::ostream& os,const vect2& obj);		