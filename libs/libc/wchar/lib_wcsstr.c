/****************************************************************************
 * libs/libc/wchar/lib_wcsstr.c
 *
 * Copyright © 2005-2014 Rich Felker, et al.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <wchar.h>
#include <sys/param.h>

/****************************************************************************
 * Private Functions
 ****************************************************************************/

static FAR wchar_t *twoway_wcsstr(FAR const wchar_t *h, FAR const wchar_t *n)
{
  FAR const wchar_t *z;
  size_t l;
  ssize_t ip;
  size_t jp;
  size_t k;
  size_t p;
  size_t ms;
  size_t p0;
  size_t mem;
  size_t mem0;

  /* Computing length of needle */

  for (l = 0; n[l] && h[l]; l++);

  /* hit the end of h */

  if (n[l])
    {
      return 0;
    }

  /* Compute maximal suffix */

  ip = -1; jp = 0; k = p = 1;

  while (jp + k < l)
    {
      if (n[ip + k] == n[jp + k])
        {
          if (k == p)
            {
              jp += p;
              k = 1;
            }
          else k++;
        }
      else if (n[ip + k] > n[jp + k])
        {
          jp += k;
          k = 1;
          p = jp - ip;
        }
      else
        {
          ip = jp++;
          k = p = 1;
        }
    }

  ms = ip;
  p0 = p;

  /* And with the opposite comparison */

  ip = -1; jp = 0; k = p = 1;
  while (jp + k < l)
    {
      if (n[ip + k] == n[jp + k])
        {
          if (k == p)
            {
              jp += p;
              k = 1;
            }
          else k++;
        }
      else if (n[ip + k] < n[jp + k])
        {
          jp += k;
          k = 1;
          p = jp - ip;
        }
      else
        {
          ip = jp++;
          k = p = 1;
        }
    }

  if (ip + 1 > ms + 1)
    {
      ms = ip;
    }
  else
    {
      p = p0;
    }

  /* Periodic needle? */

  if (wmemcmp(n, n + p, ms + 1))
    {
      mem0 = 0;
      p = MAX(ms, l - ms - 1) + 1;
    }
  else
    {
      mem0 = l - p;
    }

  mem = 0;

  /* Initialize incremental end-of-haystack pointer */

  z = h;

  /* Search loop */

  for (; ; )
    {
      /* Update incremental end-of-haystack pointer */

      if (z - h < l)
        {
          /* Fast estimate for MIN(l,63) */

          size_t grow = l | 63;
          FAR const wchar_t *z2 = wmemchr(z, 0, grow);
          if (z2)
            {
              z = z2;
              if (z - h < l)
                {
                  return 0;
                }
            }
          else z += grow;
        }

      /* Compare right half */

      for (k = MAX(ms + 1, mem); n[k] && n[k] == h[k]; k++);
      if (n[k])
        {
          h += k - ms;
          mem = 0;
          continue;
        }

      /* Compare left half */

      for (k = ms + 1; k > mem && n[k - 1] == h[k - 1]; k--);

      if (k <= mem)
        {
          return (FAR wchar_t *)h;
        }

      h += p;
      mem = mem0;
    }
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: wcsstr
 *
 * Description:
 *    Locate substring of wide string
 *
 * Input Parameters:
 *   h - the wide string to be scanned
 *   n - the wide string containing the sequence of characters to match
 *
 * Returned Value:
 *   Return a pointer to the first occurrence in "h" of the entire sequence
 *   of characters specified in "n";
 *   Return null pointer if the sequence is not present in "h"
 *
 ****************************************************************************/

FAR wchar_t *wcsstr(FAR const wchar_t *h, FAR const wchar_t *n)
{
  /* Return immediately on empty needle or haystack */

  if (!n[0])
    {
      return (FAR wchar_t *)h;
    }

  if (!h[0])
    {
      return 0;
    }

  /* Use faster algorithms for short needles */

  h = wcschr(h, *n);
  if (!h || !n[1])
    {
      return (FAR wchar_t *)h;
    }

  if (!h[1])
    {
      return 0;
    }

  return twoway_wcsstr(h, n);
}
