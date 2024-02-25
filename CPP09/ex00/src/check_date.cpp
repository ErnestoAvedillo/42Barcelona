/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_date.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:09:52 by eavedill          #+#    #+#             */
/*   Updated: 2024/02/25 14:32:53 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool checkdate(int m, int d, int y)
{
  if (! (1582<= y )  )
	 return false;
  if (! (1<= m && m<=12) )
	 return false;
  if (! (1<= d && d<=31) )
	 return false;
  if ( (d==31) && (m==2 || m==4 || m==6 || m==9 || m==11) )
	 return false;
  if ( (d==30) && (m==2) )
	 return false;
  if ( (m==2) && (d==29) && (y%4!=0) )
	 return false;
  if ( (m==2) && (d==29) && (y%400==0) )
	 return true;
  if ( (m==2) && (d==29) && (y%100==0) )
	 return false;
  if ( (m==2) && (d==29) && (y%4==0)  )
	 return true;
 
  return true;
}
