# Create library for new extension
add_library(BaseGraph_compiledfeature compiled_feature.cpp)

# Instruct BaseGraph to track this extension
add_extension(BaseGraph_compiledfeature)
