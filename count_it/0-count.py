#!/usr/bin/python3
"""
Recursive keyword counter using Reddit API
"""

import re
import requests
from collections import defaultdict


def count_words(subreddit, word_list, after=None, counter=None):
    """
    Recursively queries the Reddit API, parses hot post titles,
    and counts occurrences of words from word_list.
    """
    if counter is None:
        counter = defaultdict(int)

    headers = {'User-Agent': 'holberton-reddit-counter'}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'limit': 100, 'after': after}

    try:
        response = requests.get(url, headers=headers,
                                params=params, allow_redirects=False)
        if response.status_code != 200:
            return

        data = response.json().get('data', {})
        posts = data.get('children', [])

        # Normalize word list (handle duplicates)
        normalized = [word.lower() for word in word_list]

        for post in posts:
            title = post.get('data', {}).get('title', '').lower()
            words_in_title = re.findall(r'\b\w+\b', title)
            for word in normalized:
                counter[word] += words_in_title.count(word)

        if data.get('after'):
            return count_words(subreddit, word_list, data.get('after'), counter)
        else:
            # Sort and print final results
            filtered = {k: v for k, v in counter.items() if v > 0}
            for word, count in sorted(filtered.items(), key=lambda x: (-x[1], x[0])):
                print(f"{word}: {count}")
    except Exception:
        return
