#include "table.h"

Table Table::table_;
size_t Table::id_max_size = 2;
size_t Table::type_max_size = 4;
size_t Table::name_max_size = 4;
size_t Table::phone_max_size = 5;
size_t Table::mail_max_size = 4;
size_t Table::department_max_size = 10;

Table* Table::GetInstance(const std::string& path){
    if(table_.path != path) {
        table_.path = path;
    }
    return &table_;
}

template <typename Stream>
void filler(Stream& stream, char c, const size_t& cnt){
    stream << "+";
    stream << std::setfill(c) << std::setw(cnt) << "";
    stream << "+" << std::endl;
}

bool compare_set_field(size_t& to_field, const size_t& from_field){
    if(to_field < from_field){
        to_field = from_field;
        return true;
    }
    return false;
}

Table::~Table(){
    std::ofstream f_stream;

    if (path.find(".txt") == std::string::npos) {
        path += ".txt";
    }

    f_stream.open(path, std::ios::out);
    const std::map<std::string, size_t> column{ {"id",id_max_size},{"name",name_max_size},{"type",type_max_size},
        {"phone",phone_max_size},{"mail",mail_max_size},{"department",department_max_size} };
    size_t sum = (column.size() * 3) - 1;
    std::for_each(column.begin(),column.end(),[&](const auto& element){
        sum+=element.second;
    });

    filler(f_stream,'-',sum);
    f_stream << std::left << std::setfill(' ') << std::setw(sum) << "| ACCOUNTS" << " |" << std::endl;
    f_stream << std::flush;
    filler(f_stream,'=',sum);
    f_stream << std::left << "| " << std::setw(column.at("id")) << std::setfill(' ') << "ID" << " | " << std::setw(column.at("type")) << std::setfill(' ') << "type"
    << " | " << std::setw(column.at("name")) << std::setfill(' ') << "name" << " | " << std::setw(column.at("phone")) << std::setfill(' ') << "phone"
    << " | " << std::setw(column.at("mail")) << std::setfill(' ') << "mail" << " | " << std::setw(column.at("department")) << std::setfill(' ') << "department" << " |\n";
    filler(f_stream,'=',sum);
    for(const auto& c : table){
        c.second->getAllData(f_stream,column);
        filler(f_stream,'-',sum);
    }

    f_stream.close();
}

void Table::clearAll(){
    table.clear();
}

bool Table::deleteRecord(int id){
    return table.erase(id);
}