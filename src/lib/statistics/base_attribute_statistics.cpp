#include "base_attribute_statistics.hpp"

namespace hyrise {

BaseAttributeStatistics::BaseAttributeStatistics(const DataType init_data_type) : data_type(init_data_type) {}

std::shared_ptr<BaseAttributeStatistics> BaseAttributeStatistics::pruned(
    const size_t num_values_pruned, const PredicateCondition predicate_condition, const AllTypeVariant& variant_value,
    const std::optional<AllTypeVariant>& variant_value2) const {
  Fail("Pruning has not yet been implemented for the given statistics object");
}

}  // namespace hyrise
