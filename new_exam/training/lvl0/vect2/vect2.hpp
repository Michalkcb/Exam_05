/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:14:17 by mbany             #+#    #+#             */
/*   Updated: 2025/09/23 18:26:41 by mbany            ###   ########.fr       */
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

		vect2& operator=(const vect2& source);
		
		bool operator==(const vect2& source) const;
		bool operator!=(const vect2& source) const;
		

	
};
std::ostream& operator<<(std::ostream& os, const vect2& obj);