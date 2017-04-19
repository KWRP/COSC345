#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#import <msxml6r.dll> rename_namespace(_T("MSXML"))

int main(int argc, char* argv[])
{
	HRESULT hr = CoInitialize(NULL);
	if (SUCCEEDED(hr))
	{
		try
		{
			MSXML::IXMLDOMDocument2Ptr xmlDoc;
			hr = xmlDoc.CreateInstance(__uuidof(MSXML::DOMDocument60), NULL, CLSCTX_INPROC_SERVER);
			// TODO: if (FAILED(hr))...

			if (xmlDoc->load(_T("input.xml")) != VARIANT_TRUE)
			{
				printf("Unable to load input.xml\n");
			}
			else
			{
				printf("XML was successfully loaded\n");

				xmlDoc->setProperty("SelectionLanguage", "XPath");
				MSXML::IXMLDOMNodeListPtr wheels = xmlDoc->selectNodes("/Car/Wheels/*");
				printf("Car has %u wheels\n", wheels->Getlength());

				MSXML::IXMLDOMNodePtr node;
				node = xmlDoc->createNode(MSXML::NODE_ELEMENT, _T("Engine"), _T(""));
				node->text = _T("Engine 1.0");
				xmlDoc->documentElement->appendChild(node);
				hr = xmlDoc->save(_T("output.xml"));
				if (SUCCEEDED(hr))
					printf("output.xml successfully saved\n");
			}
		}
		catch (_com_error &e)
		{
			printf("ERROR: %ws\n", e.ErrorMessage());
		}
		CoUninitialize();
	}
	return 0;
}