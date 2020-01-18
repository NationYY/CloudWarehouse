// SFExpressReconciliation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "BasicExcel.hpp"
using namespace YCompoundFiles;
using namespace YExcel;
int _tmain(int argc, _TCHAR* argv[])
{
	BasicExcel sfExcel;

	// Load a workbook with one sheet, display its contents and
	// save into another file.
	sfExcel.Load("./028JS02_0286795960-201912.xls");
	BasicExcelWorksheet* sfSheet = sfExcel.GetWorksheet(L"Sheet0");
	if(sfSheet)
	{
		size_t maxRows = sfSheet->GetTotalRows();
		size_t maxCols = sfSheet->GetTotalCols();
		//load tile
		int colNumber = -1;
		int colWeight = -1;
		int colVAServices = -1;
		bool bFix = false;
		for(size_t c = 0; c < maxCols; ++c)
		{
			BasicExcelCell* cell = sfSheet->Cell(0, c);
			std::wstring strTitle = cell->GetWString();
			if(strTitle == L"�˵�����")
				colNumber = c;
			else if(strTitle == L"�Ʒ�����")
				colWeight = c;
			else if(strTitle == L"��ֵ����")
				colVAServices = c;
			else if(strTitle == L"�Ƿ��Ѵ���")
				bFix = true;
		}
		if(!bFix)
			sfSheet->Cell(0,maxCols)->SetWString(L"�Ƿ��Ѵ���");


		for(size_t r = 1; r < maxRows; ++r)
		{
			BasicExcelCell* cell = sfSheet->Cell(r, colNumber);
			wstring cell->GetWString()
			
			cell = sfSheet->Cell(r, colWeight);
			cell->GetWString()
		}
		sfExcel.Save();
		//
	}
	system("pause");
	return 0;
}

