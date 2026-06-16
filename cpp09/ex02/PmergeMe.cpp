#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe PmergeMe::operator=(const PmergeMe &obj)
{
	(void) obj;
	return (obj);
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	(void) obj;
}


int PmergeMe::jacobsthal(int n)
{
    return (static_cast<int>((1 << (n + 1)) + ((n % 2 == 0) ? 1 : -1)) / 3);
}


std::deque<int> PmergeMe::InsertOrderdeque(int size)
{
    std::deque<int> order;
    std::deque<int> jacob;

    for (int i = 0; ; i++)
    {
        int j = jacobsthal(i);
        if (j >= size)
            break;
        jacob.push_back(j);
    }

    int prev = 0;

    for (int k = 0; k < (int)jacob.size(); k++)
    {
        int curr = jacob[k];
        for (int i = curr; i > prev; i--)
        {
            order.push_back(i);
        }
        prev = curr;
    }
    for (int i = size - 1; i > prev; i--)
        order.push_back(i);
    return (order);
}


std::vector<int> PmergeMe::InsertOrder(int size)
{
    std::vector<int> order;
    std::vector<int> jacob;

    for (int i = 0; ; i++)
    {
        int j = jacobsthal(i);
        if (j >= size)
            break;
        jacob.push_back(j);
    }

    int prev = 0;

    for (int k = 0; k < (int)jacob.size(); k++)
    {
        int curr = jacob[k];
        for (int i = curr; i > prev; i--)
        {
            order.push_back(i);
        }
        prev = curr;
    }
    for (int i = size - 1; i > prev; i--)
        order.push_back(i);
    return (order);
}


void	PmergeMe::fill_containers(char **argv, int argc)
{
	std::cout << "Start : ";
	for (int i = 1; i < argc; i++)
	{
	
		std::cout << atoi(argv[i]) << " ";
		vec.push_back(atoi(argv[i]));
		deq.push_back(atoi(argv[i]));
	}
	std::cout << std::endl;
}

void PmergeMe::FordJohnson(std::vector<int> &vec)
{
    std::vector<int> max;
    std::vector<std::pair<int, int> > pairs(vec.size() / 2);
    int index = 0;
    int i = 0;
    bool hasStraggler = false;
    int straggler = 0;

    if (vec.size() < 2)
        return;

    if (vec.size() == 2)
    {
        if (vec[0] > vec[1])
            std::swap(vec[0], vec[1]);
        return;
    }

    if (vec.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = vec.back();
        vec.pop_back();
    }

    while (i + 1 < (int)vec.size())
    {
        if (vec[i] < vec[i + 1])
        {
            pairs[index] = std::make_pair(vec[i], vec[i + 1]);
            max.push_back(vec[i + 1]);
        }
        else
        {
            pairs[index] = std::make_pair(vec[i + 1], vec[i]);
            max.push_back(vec[i]);
        }
        i += 2;
        index++;
    }

    FordJohnson(max);

    std::vector<int> sortmin(max.size());

    for (int j = 0; j < (int)max.size(); j++)
    {
        for (int k = 0; k < (int)pairs.size(); k++)
        {
            if (pairs[k].second == max[j])
            {
                sortmin[j] = pairs[k].first;
                pairs[k].second = -1;
                break;
            }
        }
    }

    std::vector<int> main;
    main.push_back(sortmin[0]);

    for (int j = 0; j < (int)max.size(); j++)
        main.push_back(max[j]);

    if (sortmin.size() > 1)
    {
        std::vector<int> minpend(sortmin.begin() + 1, sortmin.end());
        std::vector<int> order;

        int n = 1;
        while (true)
        {
            int j = jacobsthal(n);
            if (j > (int)minpend.size())
                break;
            order.push_back(j);
            n++;
        }

        int prev = 0;

        for (size_t k = 0; k < order.size(); k++)
        {
            int current = order[k];
            for (int idx = current; idx > prev; idx--)
            {
                int value = minpend[idx - 1];
                std::vector<int>::iterator pos =
                    std::lower_bound(main.begin(), main.end(), value);
                main.insert(pos, value);
            }
            prev = current;
        }

        for (int idx = minpend.size(); idx > prev; idx--)
        {
            int value = minpend[idx - 1];
            std::vector<int>::iterator pos =
                std::lower_bound(main.begin(), main.end(), value);
            main.insert(pos, value);
        }
    }
    if (hasStraggler)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(main.begin(), main.end(), straggler);
        main.insert(pos, straggler);
    }

    vec = main;
}


void PmergeMe::FordJohnsondeque(std::deque<int> &vec)
{
    std::deque<int> max;
    std::deque<std::pair<int, int> > pairs(vec.size() / 2);
    int index = 0;
    int i = 0;
    bool hasStraggler = false;
    int straggler = 0;

    if (vec.size() < 2)
        return;

    if (vec.size() == 2)
    {
        if (vec[0] > vec[1])
            std::swap(vec[0], vec[1]);
        return;
    }

    if (vec.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = vec.back();
        vec.pop_back();
    }

    while (i + 1 < (int)vec.size())
    {
        if (vec[i] < vec[i + 1])
        {
            pairs[index] = std::make_pair(vec[i], vec[i + 1]);
            max.push_back(vec[i + 1]);
        }
        else
        {
            pairs[index] = std::make_pair(vec[i + 1], vec[i]);
            max.push_back(vec[i]);
        }
        i += 2;
        index++;
    }

    FordJohnsondeque(max);

    std::vector<int> sortmin(max.size());

    for (int j = 0; j < (int)max.size(); j++)
    {
        for (int k = 0; k < (int)pairs.size(); k++)
        {
            if (pairs[k].second == max[j])
            {
                sortmin[j] = pairs[k].first;
                pairs[k].second = -1;
                break;
            }
        }
    }

    std::deque<int> main;
    main.push_back(sortmin[0]);

    for (int j = 0; j < (int)max.size(); j++)
        main.push_back(max[j]);

    if (sortmin.size() > 1)
    {
        std::deque<int> minpend(sortmin.begin() + 1, sortmin.end());
        std::deque<int> order;

        int n = 1;
        while (true)
        {
            int j = jacobsthal(n);
            if (j > (int)minpend.size())
                break;
            order.push_back(j);
            n++;
        }

        int prev = 0;

        for (size_t k = 0; k < order.size(); k++)
        {
            int current = order[k];
            for (int idx = current; idx > prev; idx--)
            {
                int value = minpend[idx - 1];
                std::deque<int>::iterator pos =
                    std::lower_bound(main.begin(), main.end(), value);
                main.insert(pos, value);
            }
            prev = current;
        }

        for (int idx = minpend.size(); idx > prev; idx--)
        {
            int value = minpend[idx - 1];
            std::deque<int>::iterator pos =
                std::lower_bound(main.begin(), main.end(), value);
            main.insert(pos, value);
        }
    }
    if (hasStraggler)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(main.begin(), main.end(), straggler);
        main.insert(pos, straggler);
    }

    vec = main;
}

struct timeval tv;
struct timezone tz;


double get_time_diff(timeval start, timeval end)
{
    return (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0; // en millisecondes
}

void PmergeMe::appairs()
{
    timeval start;
    timeval end;

    gettimeofday(&start, NULL);
    FordJohnsondeque(deq);
    gettimeofday(&end, NULL);
    std::cout << "microsecond deque time : " << get_time_diff(start, end) << std::endl;
    gettimeofday(&start, NULL);
    FordJohnson(vec);
    gettimeofday(&end, NULL);
    std::cout << "microsecond vector time : " << get_time_diff(start, end) << std::endl;

    // for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    //     std::cout << *it << std::endl;
}