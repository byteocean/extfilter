/*
*
*    Copyright (C) Max <max1976@mail.ru>
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#ifndef __NDPI_WRAPPER_H
#define __NDPI_WRAPPER_H

#include "main.h"
#include <ndpi_api.h>
#include <rte_config.h>
#include <rte_malloc.h>

class nDPIWrapper
{
public:
	nDPIWrapper()
	{
		src = (struct ndpi_id_struct*)rte_zmalloc(NULL,extFilter::ndpi_size_id_struct,RTE_CACHE_LINE_SIZE);
		dst = (struct ndpi_id_struct*)rte_zmalloc(NULL,extFilter::ndpi_size_id_struct,RTE_CACHE_LINE_SIZE);
		flow = (struct ndpi_flow_struct *)rte_zmalloc(NULL,extFilter::ndpi_size_flow_struct,RTE_CACHE_LINE_SIZE);
	}
	~nDPIWrapper()
	{
		ndpi_free_flow(flow);
		if(src)
			rte_free(src);
		if(dst)
			rte_free(dst);
	}

	inline struct ndpi_flow_struct *get_flow()
	{
		return flow;
	}
	inline struct ndpi_id_struct *get_src()
	{
		return src;
	}
	inline struct ndpi_id_struct *get_dst()
	{
		return dst;
	}
private:
	struct ndpi_id_struct *src;
	struct ndpi_id_struct *dst;
	struct ndpi_flow_struct *flow;
};

#endif
