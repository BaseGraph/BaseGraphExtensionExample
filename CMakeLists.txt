# Create library for new extension
add_library(compiledFeature compiled_feature.cpp)

# Instruct BaseGraph to track this extension
add_extension(compiledfeature)
