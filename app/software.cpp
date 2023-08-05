#include "software.h"
#include <vector>
#include <map>
#include <string>

void sft::UncheckAll()
{
	for (auto& category : sft::software)
		for (auto& app : category.second)
			if (app.second)
				app.second = false;
}