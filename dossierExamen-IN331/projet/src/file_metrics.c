#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void compute_file_metrics(const char *filemetrics, file_line_metrics *metrics)
{
   if (metrics == NULL)
      return;
   metrics->min_length = 0;
   metrics->max_length = 0;
   metrics->total_length = 0;
   metrics->line_count = 0;
   if (filemetrics == NULL)
      return;

   FILE *f = fopen(filemetrics, "r");
   if (!f)
      return;

   char *line = NULL;
   size_t cap = 0;
   size_t nread;
   int saw = 0;
   size_t min = (size_t)-1;
   size_t max = 0;
   unsigned long long total = 0;
   int count = 0;

   while ((nread = getline(&line, &cap, f)) != -1)
   {
      saw = 1;
      size_t len = (size_t)nread;
      if (len > 0 && line[len - 1] == '\n')
         len--;
      total += len;
      if (len < min)
         min = len;
      if (len > max)
         max = len;
      count++;
   }

   free(line);
   fclose(f);

   if (!saw || count == 0)
   {
      metrics->min_length = 0;
      metrics->max_length = 0;
      metrics->total_length = 0;
      metrics->line_count = 0;
      return;
   }

   metrics->line_count = count;
   metrics->min_length = (min > (size_t)INT_MAX) ? INT_MAX : (int)min;
   metrics->max_length = (max > (size_t)INT_MAX) ? INT_MAX : (int)max;
   metrics->total_length = (total > (unsigned long long)INT_MAX) ? INT_MAX : (int)total;
}