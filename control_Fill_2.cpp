
void FILL_2D_1L_2()
{
	if(CBG_1LpT->size() > 3)
	{
		hBG_1L4C->Fill(MBG_1L, (*CBG_1LpT)[3]);
		hBG_1L3C->Fill(MBG_1L, (*CBG_1LpT)[2]);
		hBG_1L2C->Fill(MBG_1L, (*CBG_1LpT)[1]);
		hBG_1L1C->Fill(MBG_1L, (*CBG_1LpT)[0]);
		BG_1L4C->Fill((*CBG_1LpT)[3]);
		BG_1L3C->Fill((*CBG_1LpT)[2]);
		BG_1L2C->Fill((*CBG_1LpT)[1]);
		BG_1L1C->Fill((*CBG_1LpT)[0]);
	}                          
	else if(CBG_1LpT->size() > 2)
	{                          
		hBG_1L3C->Fill(MBG_1L, (*CBG_1LpT)[2]);
		hBG_1L2C->Fill(MBG_1L, (*CBG_1LpT)[1]);
		hBG_1L1C->Fill(MBG_1L, (*CBG_1LpT)[0]);
		BG_1L3C->Fill((*CBG_1LpT)[2]);
		BG_1L2C->Fill((*CBG_1LpT)[1]);
		BG_1L1C->Fill((*CBG_1LpT)[0]);
	}                          
	else if(CBG_1LpT->size() > 1)
	{                          
		hBG_1L2C->Fill(MBG_1L, (*CBG_1LpT)[1]);
		hBG_1L1C->Fill(MBG_1L, (*CBG_1LpT)[0]);
		BG_1L2C->Fill((*CBG_1LpT)[1]);
		BG_1L1C->Fill((*CBG_1LpT)[0]);
	}                          
	else if(CBG_1LpT->size() > 0)
	{
		hBG_1L1C->Fill(MBG_1L, (*CBG_1LpT)[0]);
		BG_1L1C->Fill((*CBG_1LpT)[0]);
	}

	return;
}
void FILL_2D_2L_2()
{
	if(CBG_2LpT->size() > 3)
	{
		hBG_2L4C->Fill(MBG_2L, (*CBG_2LpT)[3]);
		hBG_2L3C->Fill(MBG_2L, (*CBG_2LpT)[2]);
		hBG_2L2C->Fill(MBG_2L, (*CBG_2LpT)[1]);
		hBG_2L1C->Fill(MBG_2L, (*CBG_2LpT)[0]);
		BG_2L4C->Fill((*CBG_2LpT)[3]);
		BG_2L3C->Fill((*CBG_2LpT)[2]);
		BG_2L2C->Fill((*CBG_2LpT)[1]);
		BG_2L1C->Fill((*CBG_2LpT)[0]);
	}                          
	else if(CBG_2LpT->size() > 2)
	{                          
		hBG_2L3C->Fill(MBG_2L, (*CBG_2LpT)[2]);
		hBG_2L2C->Fill(MBG_2L, (*CBG_2LpT)[1]);
		hBG_2L1C->Fill(MBG_2L, (*CBG_2LpT)[0]);
		BG_2L3C->Fill((*CBG_2LpT)[2]);
		BG_2L2C->Fill((*CBG_2LpT)[1]);
		BG_2L1C->Fill((*CBG_2LpT)[0]);
	}                          
	else if(CBG_2LpT->size() > 1)
	{                          
		hBG_2L2C->Fill(MBG_2L, (*CBG_2LpT)[1]);
		hBG_2L1C->Fill(MBG_2L, (*CBG_2LpT)[0]);
		BG_2L2C->Fill((*CBG_2LpT)[1]);
		BG_2L1C->Fill((*CBG_2LpT)[0]);
	}                          
	else  if(CBG_2LpT->size() > 0)
	{
		hBG_2L1C->Fill(MBG_2L, (*CBG_2LpT)[0]);
		BG_2L1C->Fill((*CBG_2LpT)[0]);
	}

	return;
}
void FILL_2D_3L_2()
{
	if(CBG_3LpT->size() > 3)
	{
		hBG_3L4C->Fill(MBG_3L, (*CBG_3LpT)[3]);
		hBG_3L3C->Fill(MBG_3L, (*CBG_3LpT)[2]);
		hBG_3L2C->Fill(MBG_3L, (*CBG_3LpT)[1]);
		hBG_3L1C->Fill(MBG_3L, (*CBG_3LpT)[0]);
		BG_3L4C->Fill((*CBG_3LpT)[3]);
		BG_3L3C->Fill((*CBG_3LpT)[2]);
		BG_3L2C->Fill((*CBG_3LpT)[1]);
		BG_3L1C->Fill((*CBG_3LpT)[0]);
	}                          
	else if(CBG_3LpT->size() > 2)
	{                          
		hBG_3L3C->Fill(MBG_3L, (*CBG_3LpT)[2]);
		hBG_3L2C->Fill(MBG_3L, (*CBG_3LpT)[1]);
		hBG_3L1C->Fill(MBG_3L, (*CBG_3LpT)[0]);
		BG_3L3C->Fill((*CBG_3LpT)[2]);
		BG_3L2C->Fill((*CBG_3LpT)[1]);
		BG_3L1C->Fill((*CBG_3LpT)[0]);
	}                          
	else if(CBG_3LpT->size() > 1)
	{                          
		hBG_3L2C->Fill(MBG_3L, (*CBG_3LpT)[1]);
		hBG_3L1C->Fill(MBG_3L, (*CBG_3LpT)[0]);
		BG_3L2C->Fill((*CBG_3LpT)[1]);
		BG_3L1C->Fill((*CBG_3LpT)[0]);
	}                          
	else  if(CBG_3LpT->size() > 0)
	{
		hBG_3L1C->Fill(MBG_3L, (*CBG_3LpT)[0]);
		BG_3L1C->Fill((*CBG_3LpT)[0]);
	}

	return;
}
void FILL_2D_4L_2()
{
	if(CBG_4LpT->size() > 3)
	{
		hBG_4L4C->Fill(MBG_4L, (*CBG_4LpT)[3]);
		hBG_4L3C->Fill(MBG_4L, (*CBG_4LpT)[2]);
		hBG_4L2C->Fill(MBG_4L, (*CBG_4LpT)[1]);
		hBG_4L1C->Fill(MBG_4L, (*CBG_4LpT)[0]);
		BG_4L4C->Fill((*CBG_4LpT)[3]);
		BG_4L3C->Fill((*CBG_4LpT)[2]);
		BG_4L2C->Fill((*CBG_4LpT)[1]);
		BG_4L1C->Fill((*CBG_4LpT)[0]);
	}                          
	else if(CBG_4LpT->size() > 2)
	{                          
		hBG_4L3C->Fill(MBG_4L, (*CBG_4LpT)[2]);
		hBG_4L2C->Fill(MBG_4L, (*CBG_4LpT)[1]);
		hBG_4L1C->Fill(MBG_4L, (*CBG_4LpT)[0]);
		BG_4L3C->Fill((*CBG_4LpT)[2]);
		BG_4L2C->Fill((*CBG_4LpT)[1]);
		BG_4L1C->Fill((*CBG_4LpT)[0]);
	}                          
	else if(CBG_4LpT->size() > 1)
	{                          
		hBG_4L2C->Fill(MBG_4L, (*CBG_4LpT)[1]);
		hBG_4L1C->Fill(MBG_4L, (*CBG_4LpT)[0]);
		BG_4L2C->Fill((*CBG_4LpT)[1]);
		BG_4L1C->Fill((*CBG_4LpT)[0]);
	}                          
	else  if(CBG_4LpT->size() > 0)
	{
		hBG_4L1C->Fill(MBG_4L, (*CBG_4LpT)[0]);
		BG_4L1C->Fill((*CBG_4LpT)[0]);
	}

	return;
}
void FILL_2D_5L_2()
{
	if(CBG_5LpT->size() > 3)
	{
		hBG_5L4C->Fill(MBG_5L, (*CBG_5LpT)[3]);
		hBG_5L3C->Fill(MBG_5L, (*CBG_5LpT)[2]);
		hBG_5L2C->Fill(MBG_5L, (*CBG_5LpT)[1]);
		hBG_5L1C->Fill(MBG_5L, (*CBG_5LpT)[0]);
		BG_5L4C->Fill((*CBG_5LpT)[3]);
		BG_5L3C->Fill((*CBG_5LpT)[2]);
		BG_5L2C->Fill((*CBG_5LpT)[1]);
		BG_5L1C->Fill((*CBG_5LpT)[0]);
	}                          
	else if(CBG_5LpT->size() > 2)
	{                          
		hBG_5L3C->Fill(MBG_5L, (*CBG_5LpT)[2]);
		hBG_5L2C->Fill(MBG_5L, (*CBG_5LpT)[1]);
		hBG_5L1C->Fill(MBG_5L, (*CBG_5LpT)[0]);
		BG_5L3C->Fill((*CBG_5LpT)[2]);
		BG_5L2C->Fill((*CBG_5LpT)[1]);
		BG_5L1C->Fill((*CBG_5LpT)[0]);
	}                          
	else if(CBG_5LpT->size() > 1)
	{                          
		hBG_5L2C->Fill(MBG_5L, (*CBG_5LpT)[1]);
		hBG_5L1C->Fill(MBG_5L, (*CBG_5LpT)[0]);
		BG_5L2C->Fill((*CBG_5LpT)[1]);
		BG_5L1C->Fill((*CBG_5LpT)[0]);
	}                          
	else  if(CBG_5LpT->size() > 0)
	{
		hBG_5L1C->Fill(MBG_5L, (*CBG_5LpT)[0]);
		BG_5L1C->Fill((*CBG_5LpT)[0]);
	}

	return;
}

void FILL_2D_1La_2()
{
	if(CBGa_1LpT->size() > 3)
	{
		hBGa_1L4C->Fill(MBGa_1L, (*CBGa_1LpT)[3]);
		hBGa_1L3C->Fill(MBGa_1L, (*CBGa_1LpT)[2]);
		hBGa_1L2C->Fill(MBGa_1L, (*CBGa_1LpT)[1]);
		hBGa_1L1C->Fill(MBGa_1L, (*CBGa_1LpT)[0]);
		BGa_1L4C->Fill((*CBGa_1LpT)[3]);
		BGa_1L3C->Fill((*CBGa_1LpT)[2]);
		BGa_1L2C->Fill((*CBGa_1LpT)[1]);
		BGa_1L1C->Fill((*CBGa_1LpT)[0]);
	}                          
	else if(CBGa_1LpT->size() > 2)
	{                          
		hBGa_1L3C->Fill(MBGa_1L, (*CBGa_1LpT)[2]);
		hBGa_1L2C->Fill(MBGa_1L, (*CBGa_1LpT)[1]);
		hBGa_1L1C->Fill(MBGa_1L, (*CBGa_1LpT)[0]);
		BGa_1L3C->Fill((*CBGa_1LpT)[2]);
		BGa_1L2C->Fill((*CBGa_1LpT)[1]);
		BGa_1L1C->Fill((*CBGa_1LpT)[0]);
	}                          
	else if(CBGa_1LpT->size() > 1)
	{                          
		hBGa_1L2C->Fill(MBGa_1L, (*CBGa_1LpT)[1]);
		hBGa_1L1C->Fill(MBGa_1L, (*CBGa_1LpT)[0]);
		BGa_1L2C->Fill((*CBGa_1LpT)[1]);
		BGa_1L1C->Fill((*CBGa_1LpT)[0]);
	}                          
	else if(CBGa_1LpT->size() > 0)
	{
		hBGa_1L1C->Fill(MBGa_1L, (*CBGa_1LpT)[0]);
		BGa_1L1C->Fill((*CBGa_1LpT)[0]);
	}

	return;
}
void FILL_2D_2La_2()
{
	if(CBGa_2LpT->size() > 3)
	{
		hBGa_2L4C->Fill(MBGa_2L, (*CBGa_2LpT)[3]);
		hBGa_2L3C->Fill(MBGa_2L, (*CBGa_2LpT)[2]);
		hBGa_2L2C->Fill(MBGa_2L, (*CBGa_2LpT)[1]);
		hBGa_2L1C->Fill(MBGa_2L, (*CBGa_2LpT)[0]);
		BGa_2L4C->Fill((*CBGa_2LpT)[3]);
		BGa_2L3C->Fill((*CBGa_2LpT)[2]);
		BGa_2L2C->Fill((*CBGa_2LpT)[1]);
		BGa_2L1C->Fill((*CBGa_2LpT)[0]);
	}                          
	else if(CBGa_2LpT->size() > 2)
	{                          
		hBGa_2L3C->Fill(MBGa_2L, (*CBGa_2LpT)[2]);
		hBGa_2L2C->Fill(MBGa_2L, (*CBGa_2LpT)[1]);
		hBGa_2L1C->Fill(MBGa_2L, (*CBGa_2LpT)[0]);
		BGa_2L3C->Fill((*CBGa_2LpT)[2]);
		BGa_2L2C->Fill((*CBGa_2LpT)[1]);
		BGa_2L1C->Fill((*CBGa_2LpT)[0]);
	}                          
	else if(CBGa_2LpT->size() > 1)
	{                          
		hBGa_2L2C->Fill(MBGa_2L, (*CBGa_2LpT)[1]);
		hBGa_2L1C->Fill(MBGa_2L, (*CBGa_2LpT)[0]);
		BGa_2L2C->Fill((*CBGa_2LpT)[1]);
		BGa_2L1C->Fill((*CBGa_2LpT)[0]);
	}                          
	else  if(CBGa_2LpT->size() > 0)
	{
		hBGa_2L1C->Fill(MBGa_2L, (*CBGa_2LpT)[0]);
		BGa_2L1C->Fill((*CBGa_2LpT)[0]);
	}

	return;
}
void FILL_2D_3La_2()
{
	if(CBGa_3LpT->size() > 3)
	{
		hBGa_3L4C->Fill(MBGa_3L, (*CBGa_3LpT)[3]);
		hBGa_3L3C->Fill(MBGa_3L, (*CBGa_3LpT)[2]);
		hBGa_3L2C->Fill(MBGa_3L, (*CBGa_3LpT)[1]);
		hBGa_3L1C->Fill(MBGa_3L, (*CBGa_3LpT)[0]);
		BGa_3L4C->Fill((*CBGa_3LpT)[3]);
		BGa_3L3C->Fill((*CBGa_3LpT)[2]);
		BGa_3L2C->Fill((*CBGa_3LpT)[1]);
		BGa_3L1C->Fill((*CBGa_3LpT)[0]);
	}                          
	else if(CBGa_3LpT->size() > 2)
	{                          
		hBGa_3L3C->Fill(MBGa_3L, (*CBGa_3LpT)[2]);
		hBGa_3L2C->Fill(MBGa_3L, (*CBGa_3LpT)[1]);
		hBGa_3L1C->Fill(MBGa_3L, (*CBGa_3LpT)[0]);
		BGa_3L3C->Fill((*CBGa_3LpT)[2]);
		BGa_3L2C->Fill((*CBGa_3LpT)[1]);
		BGa_3L1C->Fill((*CBGa_3LpT)[0]);
	}                          
	else if(CBGa_3LpT->size() > 1)
	{                          
		hBGa_3L2C->Fill(MBGa_3L, (*CBGa_3LpT)[1]);
		hBGa_3L1C->Fill(MBGa_3L, (*CBGa_3LpT)[0]);
		BGa_3L2C->Fill((*CBGa_3LpT)[1]);
		BGa_3L1C->Fill((*CBGa_3LpT)[0]);
	}                          
	else  if(CBGa_3LpT->size() > 0)
	{
		hBGa_3L1C->Fill(MBGa_3L, (*CBGa_3LpT)[0]);
		BGa_3L1C->Fill((*CBGa_3LpT)[0]);
	}

	return;
}
void FILL_2D_4La_2()
{
	if(CBGa_4LpT->size() > 3)
	{
		hBGa_4L4C->Fill(MBGa_4L, (*CBGa_4LpT)[3]);
		hBGa_4L3C->Fill(MBGa_4L, (*CBGa_4LpT)[2]);
		hBGa_4L2C->Fill(MBGa_4L, (*CBGa_4LpT)[1]);
		hBGa_4L1C->Fill(MBGa_4L, (*CBGa_4LpT)[0]);
		BGa_4L4C->Fill((*CBGa_4LpT)[3]);
		BGa_4L3C->Fill((*CBGa_4LpT)[2]);
		BGa_4L2C->Fill((*CBGa_4LpT)[1]);
		BGa_4L1C->Fill((*CBGa_4LpT)[0]);
	}                          
	else if(CBGa_4LpT->size() > 2)
	{                          
		hBGa_4L3C->Fill(MBGa_4L, (*CBGa_4LpT)[2]);
		hBGa_4L2C->Fill(MBGa_4L, (*CBGa_4LpT)[1]);
		hBGa_4L1C->Fill(MBGa_4L, (*CBGa_4LpT)[0]);
		BGa_4L3C->Fill((*CBGa_4LpT)[2]);
		BGa_4L2C->Fill((*CBGa_4LpT)[1]);
		BGa_4L1C->Fill((*CBGa_4LpT)[0]);
	}                          
	else if(CBGa_4LpT->size() > 1)
	{                          
		hBGa_4L2C->Fill(MBGa_4L, (*CBGa_4LpT)[1]);
		hBGa_4L1C->Fill(MBGa_4L, (*CBGa_4LpT)[0]);
		BGa_4L2C->Fill((*CBGa_4LpT)[1]);
		BGa_4L1C->Fill((*CBGa_4LpT)[0]);
	}                          
	else  if(CBGa_4LpT->size() > 0)
	{
		hBGa_4L1C->Fill(MBGa_4L, (*CBGa_4LpT)[0]);
		BGa_4L1C->Fill((*CBGa_4LpT)[0]);
	}

	return;
}
void FILL_2D_5La_2()
{
	if(CBGa_5LpT->size() > 3)
	{
		hBGa_5L4C->Fill(MBGa_5L, (*CBGa_5LpT)[3]);
		hBGa_5L3C->Fill(MBGa_5L, (*CBGa_5LpT)[2]);
		hBGa_5L2C->Fill(MBGa_5L, (*CBGa_5LpT)[1]);
		hBGa_5L1C->Fill(MBGa_5L, (*CBGa_5LpT)[0]);
		BGa_5L4C->Fill((*CBGa_5LpT)[3]);
		BGa_5L3C->Fill((*CBGa_5LpT)[2]);
		BGa_5L2C->Fill((*CBGa_5LpT)[1]);
		BGa_5L1C->Fill((*CBGa_5LpT)[0]);
	}                          
	else if(CBGa_5LpT->size() > 2)
	{                          
		hBGa_5L3C->Fill(MBGa_5L, (*CBGa_5LpT)[2]);
		hBGa_5L2C->Fill(MBGa_5L, (*CBGa_5LpT)[1]);
		hBGa_5L1C->Fill(MBGa_5L, (*CBGa_5LpT)[0]);
		BGa_5L3C->Fill((*CBGa_5LpT)[2]);
		BGa_5L2C->Fill((*CBGa_5LpT)[1]);
		BGa_5L1C->Fill((*CBGa_5LpT)[0]);
	}                          
	else if(CBGa_5LpT->size() > 1)
	{                          
		hBGa_5L2C->Fill(MBGa_5L, (*CBGa_5LpT)[1]);
		hBGa_5L1C->Fill(MBGa_5L, (*CBGa_5LpT)[0]);
		BGa_5L2C->Fill((*CBGa_5LpT)[1]);
		BGa_5L1C->Fill((*CBGa_5LpT)[0]);
	}                          
	else  if(CBGa_5LpT->size() > 0)
	{
		hBGa_5L1C->Fill(MBGa_5L, (*CBGa_5LpT)[0]);
		BGa_5L1C->Fill((*CBGa_5LpT)[0]);
	}

	return;
}
