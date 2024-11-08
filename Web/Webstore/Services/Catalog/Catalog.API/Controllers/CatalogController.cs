using Catalog.API.Entities;
using Catalog.API.Repositories;
using Microsoft.AspNetCore.Mvc;

namespace Catalog.API.Controllers
{
    //Ovim bukvalno zadajemo uloge i putanje do odredjenih backend radnji koje cemo izvrsavati na serveru
    // [] -> omogucavajau nam da ubacimo promenljivu koja ono samo pretrazuje u kodu i menja je sa onim sto je pored nje
    [ApiController]
    [Route("api/v1/[controller]")]
    public class CatalogController : ControllerBase
    {
        IProductRepostories _repository; 
        // U sustini, stavljamo ovaj repozitorijum da mi bismo mogli samo direktno preko interfejsa da pristupamo nekoj bazi
        // A da ne moramo 100 puta da menjamo neku bazu ako zelimo da menjamo
        CatalogController(IProductRepostories repository) { 
            _repository = repository ?? throw new ArgumentNullException(nameof(repository));
        }

        //Ovde smo doslovno napravili get request koji koristi difoltnu putanju, i prilikom uspega ispisuje ocekivan izlaz
        [HttpGet]
        [ProducesResponseType(typeof(IEnumerable<Product>), StatusCodes.Status200OK)]
        public async Task<ActionResult<IEnumerable<Product>>> GetProducts() { 
        
            var products = await _repository.GetProducts();
            return Ok(products);
        }

        [HttpGet("{id}", Name ="GetProducts")]
        [ProducesResponseType(typeof(Product), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(Product), StatusCodes.Status404NotFound)]
        public async Task<ActionResult<Product>> GetProductById(string id) { 
            var product = await _repository.GetProductByID(id);
            if (product == null)
            {
                return NotFound(null);
            }
            return Ok(product);
        }

        [HttpGet]
        [Route("[action]/[category]")]
        [ProducesResponseType(typeof(Product), StatusCodes.Status200OK)]
        public async Task<ActionResult<IEnumerable<Product>>> GetProductByCategory(string category) { 
            var product = _repository.GetProductByCategory(category);
            if (product == null) { 
                return NotFound(null);
            }
            return Ok(product);
        
        }


        [HttpPost]
        [ProducesResponseType(typeof(Product), StatusCodes.Status201Created)]
        //Uvodimo ovde [FromBody] ovo nam omogucava da prosledim podatke iz tela zahteva
        public async Task<ActionResult<Product>> CreateProduct([FromBody] Product product) { 
            await _repository.CreateProduct(product);
            return CreatedAtAction("GetProduct", new { id = product.Id }, product);
        
        }

        [HttpPut]
        [ProducesResponseType(typeof(Product), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(Product), StatusCodes.Status404NotFound)]
        public async Task<IActionResult> UpdateProduct([FromBody] Product product) { 
            var res = await _repository.UpdateProduct(product);
            if (res == null) {
                return NotFound(null);
            }
            return Ok(res);
        }

        [HttpDelete]
        [ProducesResponseType(typeof(Product), StatusCodes.Status200OK)]
        [ProducesResponseType(typeof(Product), StatusCodes.Status404NotFound)]
        public async Task<ActionResult> DeleteProduct(string id) { 
            var res = _repository.DeleteProduct(id);
            if (res == null) { 
                return NotFound(null);
            }
            return Ok();
        }


    }
}
