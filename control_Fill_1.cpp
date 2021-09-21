
void FILL_2D_1L_1()
{
	if(C_1LpT->size() > 3)
	{
		h_1L4C->Fill(M_1L, (*C_1LpT)[3]);
		h_1L3C->Fill(M_1L, (*C_1LpT)[2]);
		h_1L2C->Fill(M_1L, (*C_1LpT)[1]);
		h_1L1C->Fill(M_1L, (*C_1LpT)[0]);
		
		SG_1L4C->Fill((*C_1LpT)[3]);
		SG_1L3C->Fill((*C_1LpT)[2]);
		SG_1L2C->Fill((*C_1LpT)[1]);
		SG_1L1C->Fill((*C_1LpT)[0]);
	}                          
	else if(C_1LpT->size() > 2)
	{                          
		h_1L3C->Fill(M_1L, (*C_1LpT)[2]);
		h_1L2C->Fill(M_1L, (*C_1LpT)[1]);
		h_1L1C->Fill(M_1L, (*C_1LpT)[0]);
		SG_1L3C->Fill((*C_1LpT)[2]);
		SG_1L2C->Fill((*C_1LpT)[1]);
		SG_1L1C->Fill((*C_1LpT)[0]);
	}                          
	else if(C_1LpT->size() > 1)
	{                          
		h_1L2C->Fill(M_1L, (*C_1LpT)[1]);
		h_1L1C->Fill(M_1L, (*C_1LpT)[0]);
		SG_1L2C->Fill((*C_1LpT)[1]);
		SG_1L1C->Fill((*C_1LpT)[0]);
	}                          
	else if(C_1LpT->size() > 0)
	{
		h_1L1C->Fill(M_1L, (*C_1LpT)[0]);
		SG_1L1C->Fill((*C_1LpT)[0]);
	}

	return;
}
void FILL_2D_2L_1()
{
	if(C_2LpT->size() > 3)
	{
		h_2L4C->Fill(M_2L, (*C_2LpT)[3]);
		h_2L3C->Fill(M_2L, (*C_2LpT)[2]);
		h_2L2C->Fill(M_2L, (*C_2LpT)[1]);
		h_2L1C->Fill(M_2L, (*C_2LpT)[0]);
		
		SG_2L4C->Fill((*C_2LpT)[3]);
		SG_2L3C->Fill((*C_2LpT)[2]);
		SG_2L2C->Fill((*C_2LpT)[1]);
		SG_2L1C->Fill((*C_2LpT)[0]);
	}                          
	else if(C_2LpT->size() > 2)
	{                          
		h_2L3C->Fill(M_2L, (*C_2LpT)[2]);
		h_2L2C->Fill(M_2L, (*C_2LpT)[1]);
		h_2L1C->Fill(M_2L, (*C_2LpT)[0]);
		SG_2L3C->Fill((*C_2LpT)[2]);
		SG_2L2C->Fill((*C_2LpT)[1]);
		SG_2L1C->Fill((*C_2LpT)[0]);
	}                          
	else if(C_2LpT->size() > 1)
	{                          
		h_2L2C->Fill(M_2L, (*C_2LpT)[1]);
		h_2L1C->Fill(M_2L, (*C_2LpT)[0]);
		SG_2L2C->Fill((*C_2LpT)[1]);
		SG_2L1C->Fill((*C_2LpT)[0]);
	}                          
	else  if(C_2LpT->size() > 0)
	{
		h_2L1C->Fill(M_2L, (*C_2LpT)[0]);
		SG_2L1C->Fill((*C_2LpT)[0]);
	}

	return;
}
void FILL_2D_3L_1()
{
	if(C_3LpT->size() > 3)
	{
		h_3L4C->Fill(M_3L, (*C_3LpT)[3]);
		h_3L3C->Fill(M_3L, (*C_3LpT)[2]);
		h_3L2C->Fill(M_3L, (*C_3LpT)[1]);
		h_3L1C->Fill(M_3L, (*C_3LpT)[0]);

		SG_3L4C->Fill((*C_3LpT)[3]);
		SG_3L3C->Fill((*C_3LpT)[2]);
		SG_3L2C->Fill((*C_3LpT)[1]);
		SG_3L1C->Fill((*C_3LpT)[0]);
	}                          
	else if(C_3LpT->size() > 2)
	{                          
		h_3L3C->Fill(M_3L, (*C_3LpT)[2]);
		h_3L2C->Fill(M_3L, (*C_3LpT)[1]);
		h_3L1C->Fill(M_3L, (*C_3LpT)[0]);
		SG_3L3C->Fill((*C_3LpT)[2]);
		SG_3L2C->Fill((*C_3LpT)[1]);
		SG_3L1C->Fill((*C_3LpT)[0]);
	}                          
	else if(C_3LpT->size() > 1)
	{                          
		h_3L2C->Fill(M_3L, (*C_3LpT)[1]);
		h_3L1C->Fill(M_3L, (*C_3LpT)[0]);
		SG_3L2C->Fill((*C_3LpT)[1]);
		SG_3L1C->Fill((*C_3LpT)[0]);
	}                          
	else  if(C_3LpT->size() > 0)
	{
		h_3L1C->Fill(M_3L, (*C_3LpT)[0]);
		SG_3L1C->Fill((*C_3LpT)[0]);
	}

	return;
}
void FILL_2D_4L_1()
{
	if(C_4LpT->size() > 3)
	{
		h_4L4C->Fill(M_4L, (*C_4LpT)[3]);
		h_4L3C->Fill(M_4L, (*C_4LpT)[2]);
		h_4L2C->Fill(M_4L, (*C_4LpT)[1]);
		h_4L1C->Fill(M_4L, (*C_4LpT)[0]);

		SG_4L4C->Fill((*C_4LpT)[3]);
		SG_4L3C->Fill((*C_4LpT)[2]);
		SG_4L2C->Fill((*C_4LpT)[1]);
		SG_4L1C->Fill((*C_4LpT)[0]);
	}                          
	else if(C_4LpT->size() > 2)
	{                          
		h_4L3C->Fill(M_4L, (*C_4LpT)[2]);
		h_4L2C->Fill(M_4L, (*C_4LpT)[1]);
		h_4L1C->Fill(M_4L, (*C_4LpT)[0]);
		SG_4L3C->Fill((*C_4LpT)[2]);
		SG_4L2C->Fill((*C_4LpT)[1]);
		SG_4L1C->Fill((*C_4LpT)[0]);
	}                          
	else if(C_4LpT->size() > 1)
	{                          
		h_4L2C->Fill(M_4L, (*C_4LpT)[1]);
		h_4L1C->Fill(M_4L, (*C_4LpT)[0]);
		SG_4L2C->Fill((*C_4LpT)[1]);
		SG_4L1C->Fill((*C_4LpT)[0]);
	}                          
	else  if(C_4LpT->size() > 0)
	{
		h_4L1C->Fill(M_4L, (*C_4LpT)[0]);
		SG_4L1C->Fill((*C_4LpT)[0]);
	}

	return;
}
void FILL_2D_5L_1()
{
	if(C_5LpT->size() > 3)
	{
		h_5L4C->Fill(M_5L, (*C_5LpT)[3]);
		h_5L3C->Fill(M_5L, (*C_5LpT)[2]);
		h_5L2C->Fill(M_5L, (*C_5LpT)[1]);
		h_5L1C->Fill(M_5L, (*C_5LpT)[0]);

		SG_5L4C->Fill((*C_5LpT)[3]);
		SG_5L3C->Fill((*C_5LpT)[2]);
		SG_5L2C->Fill((*C_5LpT)[1]);
		SG_5L1C->Fill((*C_5LpT)[0]);
	}                          
	else if(C_5LpT->size() > 2)
	{                          
		h_5L3C->Fill(M_5L, (*C_5LpT)[2]);
		h_5L2C->Fill(M_5L, (*C_5LpT)[1]);
		h_5L1C->Fill(M_5L, (*C_5LpT)[0]);
		SG_5L3C->Fill((*C_5LpT)[2]);
		SG_5L2C->Fill((*C_5LpT)[1]);
		SG_5L1C->Fill((*C_5LpT)[0]);
	}                          
	else if(C_5LpT->size() > 1)
	{                          
		h_5L2C->Fill(M_5L, (*C_5LpT)[1]);
		h_5L1C->Fill(M_5L, (*C_5LpT)[0]);
		SG_5L2C->Fill((*C_5LpT)[1]);
		SG_5L1C->Fill((*C_5LpT)[0]);
	}                          
	else  if(C_5LpT->size() > 0)
	{
		h_5L1C->Fill(M_5L, (*C_5LpT)[0]);
		SG_5L1C->Fill((*C_5LpT)[0]);
	}

	return;
}

void FILL_2D_1La_1()
{
	if(Ca_1LpT->size() > 3)
	{
		ha_1L4C->Fill(Ma_1L, (*Ca_1LpT)[3]);
		ha_1L3C->Fill(Ma_1L, (*Ca_1LpT)[2]);
		ha_1L2C->Fill(Ma_1L, (*Ca_1LpT)[1]);
		ha_1L1C->Fill(Ma_1L, (*Ca_1LpT)[0]);
		
		SGa_1L4C->Fill((*Ca_1LpT)[3]);
		SGa_1L3C->Fill((*Ca_1LpT)[2]);
		SGa_1L2C->Fill((*Ca_1LpT)[1]);
		SGa_1L1C->Fill((*Ca_1LpT)[0]);
	}                          
	else if(Ca_1LpT->size() > 2)
	{                          
		ha_1L3C->Fill(Ma_1L, (*Ca_1LpT)[2]);
		ha_1L2C->Fill(Ma_1L, (*Ca_1LpT)[1]);
		ha_1L1C->Fill(Ma_1L, (*Ca_1LpT)[0]);
		SGa_1L3C->Fill((*Ca_1LpT)[2]);
		SGa_1L2C->Fill((*Ca_1LpT)[1]);
		SGa_1L1C->Fill((*Ca_1LpT)[0]);
	}                          
	else if(Ca_1LpT->size() > 1)
	{                          
		ha_1L2C->Fill(Ma_1L, (*Ca_1LpT)[1]);
		ha_1L1C->Fill(Ma_1L, (*Ca_1LpT)[0]);
		SGa_1L2C->Fill((*Ca_1LpT)[1]);
		SGa_1L1C->Fill((*Ca_1LpT)[0]);
	}                          
	else if(Ca_1LpT->size() > 0)
	{
		ha_1L1C->Fill(Ma_1L, (*Ca_1LpT)[0]);
		SGa_1L1C->Fill((*Ca_1LpT)[0]);
	}

	return;
}
void FILL_2D_2La_1()
{
	if(Ca_2LpT->size() > 3)
	{
		ha_2L4C->Fill(Ma_2L, (*Ca_2LpT)[3]);
		ha_2L3C->Fill(Ma_2L, (*Ca_2LpT)[2]);
		ha_2L2C->Fill(Ma_2L, (*Ca_2LpT)[1]);
		ha_2L1C->Fill(Ma_2L, (*Ca_2LpT)[0]);
		
		SGa_2L4C->Fill((*Ca_2LpT)[3]);
		SGa_2L3C->Fill((*Ca_2LpT)[2]);
		SGa_2L2C->Fill((*Ca_2LpT)[1]);
		SGa_2L1C->Fill((*Ca_2LpT)[0]);
	}                          
	else if(Ca_2LpT->size() > 2)
	{                          
		ha_2L3C->Fill(Ma_2L, (*Ca_2LpT)[2]);
		ha_2L2C->Fill(Ma_2L, (*Ca_2LpT)[1]);
		ha_2L1C->Fill(Ma_2L, (*Ca_2LpT)[0]);
		SGa_2L3C->Fill((*Ca_2LpT)[2]);
		SGa_2L2C->Fill((*Ca_2LpT)[1]);
		SGa_2L1C->Fill((*Ca_2LpT)[0]);
	}                          
	else if(Ca_2LpT->size() > 1)
	{                          
		ha_2L2C->Fill(Ma_2L, (*Ca_2LpT)[1]);
		ha_2L1C->Fill(Ma_2L, (*Ca_2LpT)[0]);
		SGa_2L2C->Fill((*Ca_2LpT)[1]);
		SGa_2L1C->Fill((*Ca_2LpT)[0]);
	}                          
	else  if(Ca_2LpT->size() > 0)
	{
		ha_2L1C->Fill(Ma_2L, (*Ca_2LpT)[0]);
		SGa_2L1C->Fill((*Ca_2LpT)[0]);
	}

	return;
}
void FILL_2D_3La_1()
{
	if(Ca_3LpT->size() > 3)
	{
		ha_3L4C->Fill(Ma_3L, (*Ca_3LpT)[3]);
		ha_3L3C->Fill(Ma_3L, (*Ca_3LpT)[2]);
		ha_3L2C->Fill(Ma_3L, (*Ca_3LpT)[1]);
		ha_3L1C->Fill(Ma_3L, (*Ca_3LpT)[0]);

		SGa_3L4C->Fill((*Ca_3LpT)[3]);
		SGa_3L3C->Fill((*Ca_3LpT)[2]);
		SGa_3L2C->Fill((*Ca_3LpT)[1]);
		SGa_3L1C->Fill((*Ca_3LpT)[0]);
	}                          
	else if(Ca_3LpT->size() > 2)
	{                          
		ha_3L3C->Fill(Ma_3L, (*Ca_3LpT)[2]);
		ha_3L2C->Fill(Ma_3L, (*Ca_3LpT)[1]);
		ha_3L1C->Fill(Ma_3L, (*Ca_3LpT)[0]);
		SGa_3L3C->Fill((*Ca_3LpT)[2]);
		SGa_3L2C->Fill((*Ca_3LpT)[1]);
		SGa_3L1C->Fill((*Ca_3LpT)[0]);
	}                          
	else if(Ca_3LpT->size() > 1)
	{                          
		ha_3L2C->Fill(Ma_3L, (*Ca_3LpT)[1]);
		ha_3L1C->Fill(Ma_3L, (*Ca_3LpT)[0]);
		SGa_3L2C->Fill((*Ca_3LpT)[1]);
		SGa_3L1C->Fill((*Ca_3LpT)[0]);
	}                          
	else  if(Ca_3LpT->size() > 0)
	{
		ha_3L1C->Fill(Ma_3L, (*Ca_3LpT)[0]);
		SGa_3L1C->Fill((*Ca_3LpT)[0]);
	}

	return;
}
void FILL_2D_4La_1()
{
	if(Ca_4LpT->size() > 3)
	{
		ha_4L4C->Fill(Ma_4L, (*Ca_4LpT)[3]);
		ha_4L3C->Fill(Ma_4L, (*Ca_4LpT)[2]);
		ha_4L2C->Fill(Ma_4L, (*Ca_4LpT)[1]);
		ha_4L1C->Fill(Ma_4L, (*Ca_4LpT)[0]);

		SGa_4L4C->Fill((*Ca_4LpT)[3]);
		SGa_4L3C->Fill((*Ca_4LpT)[2]);
		SGa_4L2C->Fill((*Ca_4LpT)[1]);
		SGa_4L1C->Fill((*Ca_4LpT)[0]);
	}                          
	else if(Ca_4LpT->size() > 2)
	{                          
		ha_4L3C->Fill(Ma_4L, (*Ca_4LpT)[2]);
		ha_4L2C->Fill(Ma_4L, (*Ca_4LpT)[1]);
		ha_4L1C->Fill(Ma_4L, (*Ca_4LpT)[0]);
		SGa_4L3C->Fill((*Ca_4LpT)[2]);
		SGa_4L2C->Fill((*Ca_4LpT)[1]);
		SGa_4L1C->Fill((*Ca_4LpT)[0]);
	}                          
	else if(Ca_4LpT->size() > 1)
	{                          
		ha_4L2C->Fill(Ma_4L, (*Ca_4LpT)[1]);
		ha_4L1C->Fill(Ma_4L, (*Ca_4LpT)[0]);
		SGa_4L2C->Fill((*Ca_4LpT)[1]);
		SGa_4L1C->Fill((*Ca_4LpT)[0]);
	}                          
	else  if(Ca_4LpT->size() > 0)
	{
		ha_4L1C->Fill(Ma_4L, (*Ca_4LpT)[0]);
		SGa_4L1C->Fill((*Ca_4LpT)[0]);
	}

	return;
}
void FILL_2D_5La_1()
{
	if(Ca_5LpT->size() > 3)
	{
		ha_5L4C->Fill(Ma_5L, (*Ca_5LpT)[3]);
		ha_5L3C->Fill(Ma_5L, (*Ca_5LpT)[2]);
		ha_5L2C->Fill(Ma_5L, (*Ca_5LpT)[1]);
		ha_5L1C->Fill(Ma_5L, (*Ca_5LpT)[0]);

		SGa_5L4C->Fill((*Ca_5LpT)[3]);
		SGa_5L3C->Fill((*Ca_5LpT)[2]);
		SGa_5L2C->Fill((*Ca_5LpT)[1]);
		SGa_5L1C->Fill((*Ca_5LpT)[0]);
	}                          
	else if(Ca_5LpT->size() > 2)
	{                          
		ha_5L3C->Fill(Ma_5L, (*Ca_5LpT)[2]);
		ha_5L2C->Fill(Ma_5L, (*Ca_5LpT)[1]);
		ha_5L1C->Fill(Ma_5L, (*Ca_5LpT)[0]);
		SGa_5L3C->Fill((*Ca_5LpT)[2]);
		SGa_5L2C->Fill((*Ca_5LpT)[1]);
		SGa_5L1C->Fill((*Ca_5LpT)[0]);
	}                          
	else if(Ca_5LpT->size() > 1)
	{                          
		ha_5L2C->Fill(Ma_5L, (*Ca_5LpT)[1]);
		ha_5L1C->Fill(Ma_5L, (*Ca_5LpT)[0]);
		SGa_5L2C->Fill((*Ca_5LpT)[1]);
		SGa_5L1C->Fill((*Ca_5LpT)[0]);
	}                          
	else  if(Ca_5LpT->size() > 0)
	{
		ha_5L1C->Fill(Ma_5L, (*Ca_5LpT)[0]);
		SGa_5L1C->Fill((*Ca_5LpT)[0]);
	}

	return;
}
