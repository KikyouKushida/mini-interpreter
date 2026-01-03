

#include <memory>
#include <string>
#include <vector>
#include "token.h"
#include "ast.h"
#include "parser.h"
#include <stdexcept>

std::unique_ptr<Expr> parseExpression(TokenStream& ts) {
  std::unique_ptr<Expr> left = parseTerm(ts);
  while (ts.peek().type == TokenType::PLUS || ts.peek().type == TokenType::MINUS) {
    TokenType op = ts.consume().type;
    std::unique_ptr<Expr> right = parseTerm(ts);
    left = std::make_unique<BinaryExpr>(op, std::move(left), std::move(right));
  }
  return left;
}

std::unique_ptr<Expr> parseTerm(TokenStream& ts) {
  std::unique_ptr<Expr> left = parseFactor(ts);
  while (ts.peek().type == TokenType::MUL || ts.peek().type == TokenType::DIV) {
    TokenType op = ts.consume().type;
    std::unique_ptr<Expr> right = parseFactor(ts);
    left = std::make_unique<BinaryExpr>(op, std::move(left), std::move(right));
  }
  return left;
}

std::unique_ptr<Expr> parseFactor(TokenStream& ts) {
  if (ts.peek().type == TokenType::INT) {
    const Token& t = ts.consume();
    return std::make_unique<IntExpr>(t.value);
  } else if (ts.peek().type == TokenType::IDENT) {
    const Token& t = ts.consume();
    return std::make_unique<VarExpr>(t.lexeme);
  } else if (ts.peek().type == TokenType::LPAREN) {
    ts.consume();
    auto inside = parseExpression(ts);
    ts.expect(TokenType::RPAREN);
    return inside;
  } else {
    throw std::runtime_error(
      "Unexpected token " + tokenTypeName(ts.peek().type) +
      " ('" + ts.peek().lexeme + "') at position " +
      std::to_string(ts.peek().position)
    );
  }
}

std::unique_ptr<Expr> parseAllExpression(TokenStream& ts) {
  auto expr = parseExpression(ts);
  ts.expect(TokenType::END);
  return expr;
}

std::unique_ptr<Stmt> parseStatement(TokenStream& ts) {
  if (ts.peek().type == TokenType::IDENT) {
    std::string name = ts.consume().lexeme;
    ts.expect(TokenType::ASSIGN);
    auto expr = parseExpression(ts);
    return std::make_unique<AssignStmt>(name, std::move(expr));
  } else if (ts.peek().type == TokenType::PRINT) {
    ts.consume();
    ts.expect(TokenType::LPAREN);
    auto expr = parseExpression(ts);
    ts.expect(TokenType::RPAREN);
    return std::make_unique<PrintStmt>(std::move(expr));
  } else {
    throw std::runtime_error(
      "Unexpected token '" + ts.peek().lexeme +
      "' at position " + std::to_string(ts.peek().position)
    );
  }
}

Program parseProgram(TokenStream& ts) {
  Program program;
  while (ts.peek().type != TokenType::END) {
    program.push_back(parseStatement(ts));
  }
  return program;
}