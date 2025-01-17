#pragma once

#include <memory>
#include <string>
#include <vector>

#include "abstract_non_query_node.hpp"

namespace hyrise {

class AbstractExpression;

/**
 * Node type to represent updates (i.e., invalidation and inserts) in a table.
 */
class UpdateNode : public EnableMakeForLQPNode<UpdateNode>, public AbstractNonQueryNode {
 public:
  explicit UpdateNode(const std::string& init_table_name);

  std::string description(const DescriptionMode mode = DescriptionMode::Short) const override;
  bool is_column_nullable(const ColumnID column_id) const override;
  std::vector<std::shared_ptr<AbstractExpression>> output_expressions() const override;

  const std::string table_name;

 protected:
  size_t _on_shallow_hash() const override;
  std::shared_ptr<AbstractLQPNode> _on_shallow_copy(LQPNodeMapping& node_mapping) const override;
  bool _on_shallow_equals(const AbstractLQPNode& rhs, const LQPNodeMapping& node_mapping) const override;
};

}  // namespace hyrise
