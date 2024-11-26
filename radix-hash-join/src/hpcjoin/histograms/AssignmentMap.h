/**
 * @author  Claude Barthels <claudeb@inf.ethz.ch>
 * (c) 2016, ETH Zurich, Systems Group
 *
 */

#ifndef HPCJOIN_HISTOGRAMS_ASSIGNMENTMAP_H_
#define HPCJOIN_HISTOGRAMS_ASSIGNMENTMAP_H_

#include <stdint.h>

#include <hpcjoin/histograms/GlobalHistogram.h>

namespace hpcjoin {
namespace histograms {

class AssignmentMap {

public:
  AssignmentMap(
      uint32_t numberOfNodes,
      hpcjoin::histograms::GlobalHistogram *innerRelationGlobalHistogram,
      hpcjoin::histograms::GlobalHistogram *outerRelationGlobalHistogram);
  ~AssignmentMap();

public:
  void computePartitionAssignment();
  uint32_t *getPartitionAssignment();

protected:
  uint32_t numberOfNodes;
  hpcjoin::histograms::GlobalHistogram *innerRelationGlobalHistogram;
  hpcjoin::histograms::GlobalHistogram *outerRelationGlobalHistogram;

  uint32_t *assignment;
  // 一个和网络分区数量长度相同的数组。假设有 10 个分区，4 个进程，则初始化为
  // [0, 1, 2, 3, 0, 1, 2, 3, 0, 1]，里面的数字表示第 i 个分区属于哪个进程
};

} /* namespace histograms */
} /* namespace hpcjoin */

#endif /* HPCJOIN_HISTOGRAMS_ASSIGNMENTMAP_H_ */
