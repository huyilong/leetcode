Two unsorted array
output  3 sorted array, one of which contains the duplicated elements in both array

1, 3, 5, 7, 8, 9, 10, 11
2, 4, 6, 8, 10

Output
1, 3, 5, 7, 9, 11
2, 4, 6
8, 10


vector<int> sortTwoArrayAndOutputDuplicate(vector<int>& left, vector<int>& right)
{

	sort(left.begin(), left.end() );
	sort(right, begin(), right.end());
	int I =0, j =0;
	Int newI = 0, newJ =0;
	Vector <int>common;

	While(I <left.size() && j < right.size())
	{
		If(left < right[j])
		{
			Left[newI++] = left[i++];
		}

		Elseif (left > right[j])
		{
			Right[newJ++]= right[j++];
		}

		Else
		{
			Common.push_back(left);
		}
	}


	While (I <left.size())
	{
		Left[newI++]= left[i++];
	}

	While(j <right.size())
	{
		Right[leftJ++]= right[j++];
	}


	Left.resize(newI);
	Right.resize(newJ);

	return common;
}